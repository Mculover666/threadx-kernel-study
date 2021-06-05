#include <stdio.h>
#include "tx_api.h"
#include "main.h"

#define THREAD1_PRIO         2
#define THREAD1_STACK_SIZE   1024
static  TX_THREAD thread1;
uint8_t thread1_stack[THREAD1_STACK_SIZE];

#define THREAD2_PRIO         3
#define THREAD2_STACK_SIZE   1024
static  TX_THREAD thread2;
uint8_t thread2_stack[THREAD2_STACK_SIZE];

void my_thread1_entry(ULONG thread_input)
{
  /* Enter into a forever loop. */
  while(1)
  {
    printf("threadx 1 application running...\r\n");
    /* Sleep for 1 tick. */
    tx_thread_sleep(1000);
  }
}

void my_thread2_entry(ULONG thread_input)
{
  /* Enter into a forever loop. */
  while(1)
  {
    printf("threadx 2 application running...\r\n");
    /* Sleep for 1 tick. */
    tx_thread_sleep(1000);
  }
}

void tx_application_define(void *first_unused_memory)
{
  /* Create thread */
  tx_thread_create(&thread1, "thread 1", my_thread1_entry, 0, &thread1_stack[0], THREAD1_STACK_SIZE, THREAD1_PRIO, THREAD1_PRIO, TX_NO_TIME_SLICE, TX_AUTO_START);
    
  tx_thread_create(&thread2, "thread 2", my_thread2_entry, 0, &thread2_stack[0], THREAD2_STACK_SIZE, THREAD2_PRIO, THREAD2_PRIO, TX_NO_TIME_SLICE, TX_AUTO_START);
}
