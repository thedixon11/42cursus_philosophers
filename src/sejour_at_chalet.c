#include "../philosophers_general.h"
#include <stdalign.h>

void  fondue_time(t_data *philo)
{
  if (philo->philo_nb % 2 == 1)
  {
    pthread_mutex_lock(philo->right_fork, NULL);
    capis_printer(philo->philo_nb, ) // NOTE: have to continue there broo
    pthread_mutex_lock(philo->left_fork, NULL);
  }
  else
  {
    pthread_mutex_lock(philo->left_fork, NULL);
    pthread_mutex_lock(philo->right_fork, NULL);
  }


}

void  snoring_time(t_philo *philo)
{

}

void	*sejour_at_chalet(t_philo *philo)
{
  while (1)
  {
    fondue_time(philo);
    snoring_time(philo);
  }
}
