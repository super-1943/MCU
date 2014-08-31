/*
*********************************************************************************************************
*                                              configure file
*********************************************************************************************************
*/
#define OS_MAX_EVENTS            4    /* Max. number of event control blocks in your application ...  */
                                       /* ... MUST be >= 2                                             */
#define OS_MAX_MEM_PART          0    /* Max. number of memory partitions ...                         */
                                       /* ... MUST be >= 2                                             */
#define OS_MAX_QS                0    /* Max. number of queue control blocks in your application ...  */
                                       /* ... MUST be >= 2                                             */
#define OS_MAX_TASKS             6    /* Max. number of tasks in your application ...                 */
                                       /* ... MUST be >= 2                                             */

#define OS_LOWEST_PRIO           7    /* Defines the lowest priority that can be assigned ...         */
                                       /* ... MUST NEVER be higher than 63!                            */

#define OS_TASK_IDLE_STK_SIZE   20    /* Idle task stack size (# of 16-bit wide entries)              */

#define OS_TASK_STAT_EN          0    /* Enable (1) or Disable(0) the statistics task                 */
#define OS_TASK_STAT_STK_SIZE   32    /* Statistics task stack size (# of 16-bit wide entries)        */

#define OS_CPU_HOOKS_EN           0    /* uC/OS-II hooks are found in the processor port files         */

#define OS_TICKS_PER_SEC         20    /* Set the number of ticks in one second                        */
#define OSSCHED_LOCK_EN           0
#define OS_VERSION_CHK_EN         0

//*--------------------------------------------------------------------
#define OS_TICK_TIME              1   //* increased 50ms at every one
//*--------------------------------------------------------------------
//* OS_MEM configure 
#define OS_MEM_EN                 0   

//*--------------------------------------------------------------------
//* OS_MBOX configure 
#define OS_MBOX_EN                0 //*   
#define OS_Mbox_Accept_EN         0 //*
#define OS_Mbox_Create_EN         0 //*
#define OS_Mbox_Pend_EN           0 //*
#define OS_Mbox_Post_EN           0 //*
#define OS_Mbox_Query_EN          0 //*

//*--------------------------------------------------------------------
//* os_Q configure 
#define OS_Q_EN                   0 //* Include code for QUEUES 
#define OS_Q_Query_EN             0 //*
#define OS_Q_PostFront_EN         0 //*
#define OS_Q_Post_EN              0 //*
#define OS_Q_Pend_EN              0 //*
#define OS_Q_Flush_EN             0 //*
#define OS_Q_Create_EN            0 //*
#define OS_Q_Accept_EN            0 //*

//*--------------------------------------------------------------------
//* os_Sem configure 
#define OS_Sem_EN		  1 //* all of the follow
#define OS_Sem_Create_EN          1 //* OSSemCreate()
#define OS_Sem_Pend_EN            1 //* OSSemPend()
#define OS_Sem_Post_EN            1 //* OSSemPost()
#define OS_Sem_Accept_EN 	  0 //* OSSemAccept() 
#define OS_Sem_Query_EN		  0 //* OSSemQuery()

//*--------------------------------------------------------------------
//* os_time configure 
#define OS_Time_DlyHMSM_EN        0
#define OS_Time_Dly_EN            0
#define OS_Time_DlyResume_EN      0
#define OS_Time_Get_EN            0
#define OS_Time_Set_EN            0

//*--------------------------------------------------------------------
//* os_task configure
#define OS_TASK_CHANGE_PRIO_EN    0 //* OSTaskChangePrio()              
#define OS_TASK_CREATE_EN         1 //* OSTaskCreate()                  
#define OS_TASK_CREATE_EXT_EN     0 //* OSTaskCreateExt()               
#define OS_TASK_DEL_EN            0 //* OSTaskDel()                     
#define OS_TASK_SUSPEND_EN        0 //* OSTaskSuspend and OSTaskResume
#define OS_Task_Query_EN	  0 //* OSTaskQuery()	

//*--------------------------------------------------------------------
//* interrupt function predefine
#define USE_Pre_ExternInt0        1
#define USE_Pre_ExternInt1        1
#define USE_Pre_TimeInt1          1
#define USE_Pre_SeryInt           0