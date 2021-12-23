#include "philo.h"

static void	set_msg(int status, char **msg)
{
	if (status == THINK)
		*msg = "is thinking";
	else if (status == EAT)
		*msg = "is eating";
	else if (status == SLEEP)
		*msg = "is sleeping";
	else if (status == TAKEN_LEFT || status == TAKEN_RIGHT)
		*msg = "has taken a fork";
	else if (status == DIE)
		*msg = "died";
	else
		*msg = "WHAT!!??";
}

void	put_timestamp(int id, int status)
{
	char	*msg;
	struct timeval	tv;

	msg = NULL;
	set_msg(status, &msg);
	gettimeofday(&tv, NULL);
	printf("%ld%03lu %d %s\n", tv.tv_sec, tv.tv_usec / 1000, id, msg);
}
