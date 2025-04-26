#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int	*g_value;
int	count;

void	*routine()
{
 	*(g_value)+=5;
	count+=10;
 	printf ("the counter is %d and the g_value is %d\n", count, (*g_value));
}

int	main()
{
	int i = 0;
	pthread_t	t1[100];

	g_value = malloc(sizeof(int));
	*g_value = 0;
	if(!g_value)
	{
		return(1);
	}
	while(i < 2)
	{
		pthread_create(&t1[i], NULL, routine, NULL);
		i++;
	}
	i = 0;
	while(i < 2)
	{
		pthread_join(t1[i], NULL);
		i++;
	}
}
//
//
//
/*------------------------------------------------------------------------*/

////////////////////////////////////////////////////////////////////////////

/*void	*click_to_get(void *arg)*/
/*{*/
/*	int	*res = malloc(sizeof(int));*/
/*	*res = 42;*/
/*	return ((void	*)res);*/
/*}*/
/**/
/*int	main()*/
/*{*/
/*	pthread_t	t1[3];*/
/*	void	*ret_val;*/
/*	int i = 0;*/
/*	while (i < 3)*/
/*	{*/
/*		pthread_create(&t1[i], NULL, click_to_get, NULL);*/
/*		i++;*/
/*	}*/
/*	i = 0;*/
/*	while (i < 3)*/
/*	{*/
/*		pthread_join(t1[i], &ret_val);*/
/*		int	*res = (int *)ret_val;*/
/*		printf("%d\n", *res);*/
/*		i++;*/
/*	}*/
/*}*/





/////////////////////////////////////////////////////////////


/*void	*click_to_get(void *arg)*/
/*{*/
/*	printf ("hello the whole world\n");*/
/**/
/*	return (NULL);*/
/*}*/
/**/
/*int	main()*/
/*{*/
/*	pthread_t	t1[3];*/
/*	int i = 0;*/
/*	while (i < 3)*/
/*	{*/
/*		pthread_create(&t1[i], NULL, click_to_get, NULL);*/
/*		i++;*/
/*	}*/
/*	/*i = 0;*/
/*	/*while (i < 3)*/
/*	/*{*/
/*	pthread_join(t1[0], NULL);*/
/*	printf ("done \n");*/
/*	/*	i++;*/
/*	/*}*/
/*}*/

