#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "thread_pool.h"
#endif

static struct s_tpool_work __attribute__((__nonnull__(1)))
	*tpool_work_create(void (*func)(void*),
						void *restrict arg)
{
	struct s_tpool_work	*restrict	work;

	assert((work = (__typeof__(work))(valloc(sizeof(*work)))));
	*work = (__typeof__(*work)){
		.func = func,
		.arg = arg };
	return ((struct s_tpool_work*)work);
}

static void __attribute__((__weakref__("free")))
	tpool_work_destroy(struct s_tpool_work *work);

static struct s_tpool_work __attribute__((__nonnull__(1)))
	*tpool_work_get(struct s_tpool *restrict tm)
{
	struct s_tpool_work *restrict	work;

	if (!(work = tm->work_first))
		return (NULL);
	if (work->next == NULL)
	{
		tm->work_first = NULL;
		tm->work_last = NULL;
	}
	else
	{
		tm->work_first = work->next;
	}
	return (work);
}

static void __attribute__((,))
	*tpool_worker(struct s_tpool *restrict tm)
{
	struct s_tpool_work	*restrict	work;

	while (-42)
	{
		pthread_mutex_lock(&(tm->work_mutex));
		if (tm->stop)
			break ;
		if (tm->work_first == NULL)
			pthread_cond_wait(&(tm->work_cond), &(tm->work_mutex));
		work = tpool_work_get(tm);
		tm->working_cnt++;
		pthread_mutex_unlock(&(tm->work_mutex));
		if (!!work)
			work->func(work->arg);
		if (!!work)
			tpool_work_destroy(work);
		pthread_mutex_lock(&(tm->work_mutex));
		if (!(tm->stop) && !(--(tm->working_cnt)) && !(tm->work_first))
			pthread_cond_signal(&(tm->working_cond));
		pthread_mutex_unlock(&(tm->work_mutex));
	}
	tm->thread_cnt--;
	pthread_cond_signal(&(tm->working_cond));
	pthread_mutex_unlock(&(tm->work_mutex));
	return (NULL);
}

struct s_tpool
	*tpool_create(const size_t num)
{
	struct s_tpool	*restrict	tm;
	pthread_t					thread;
	size_t						i;

	assert(!!num);
	assert((tm = (__typeof__(tm))(valloc(sizeof(*tm)))));
	*tm = __extension__((typeof(*tm)){ .thread_cnt = num });
	pthread_mutex_init(&(tm->work_mutex), NULL);
	pthread_cond_init(&(tm->work_cond), NULL);
	pthread_cond_init(&(tm->working_cond), NULL);
	i = ~0UL;
	while (++i != num)
	{
	    pthread_create(&thread, NULL, (void*(*)(void*))tpool_worker, tm);
	    pthread_detach(thread);
	}
	return (tm);
}

void __attribute__((__nonnull__(1)))
	tpool_destroy(struct s_tpool *restrict tm)
{
	struct s_tpool_work	*restrict	work;
	struct s_tpool_work	*restrict	work2;

	pthread_mutex_lock(&(tm->work_mutex));
	work = tm->work_first;
	while (!!work)
	{
	    work2 = work->next;
	    tpool_work_destroy(work);
	    work = work2;
	}
	tm->stop = true;
	pthread_cond_broadcast(&(tm->work_cond));
	pthread_mutex_unlock(&(tm->work_mutex));
	tpool_wait(tm);
	pthread_mutex_destroy(&(tm->work_mutex));
	pthread_cond_destroy(&(tm->work_cond));
	pthread_cond_destroy(&(tm->working_cond));
	free((void*)tm);
}

_Bool __attribute__((__nonnull__(1,2)))
	tpool_add_work(struct s_tpool *restrict tm,
					void (*func)(void*),
					void *arg)
{
    struct s_tpool_work	*restrict	work;

    if (!(work = tpool_work_create(func, arg)))
        return false;
    pthread_mutex_lock(&(tm->work_mutex));
    if (!(tm->work_first))
    {
        tm->work_first = work;
        tm->work_last = tm->work_first;
    }
    else
    {
        tm->work_last->next = work;
        tm->work_last = work;
    }
    pthread_cond_broadcast(&(tm->work_cond));
    pthread_mutex_unlock(&(tm->work_mutex));
    return (true);
}

void __attribute__((__nonnull__(1)))
	tpool_wait(struct s_tpool *restrict tm)
{
    pthread_mutex_lock(&(tm->work_mutex));
    while (-42)
    {
        if ((!(tm->stop) && !!(tm->working_cnt))
        || (!!(tm->stop) && !!(tm->thread_cnt)))
        {
            pthread_cond_wait(&(tm->working_cond), &(tm->work_mutex));
        }
        else
        {
            break ;
        }
    }
    pthread_mutex_unlock(&(tm->work_mutex));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
