#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "FreeRTOS.h"
#include "task.h"



//�������ȼ�
#define START_TASK_PRIO		1
//�����ջ��С	
#define START_STK_SIZE 		128  
//������
TaskHandle_t StartTask_Handler;
//������
void start_task(void *pvParameters);

//�������ȼ�
#define TASK1_TASK_PRIO		2
//�����ջ��С	
#define TASK1_STK_SIZE 		128  
//������
TaskHandle_t Task1Task_Handler;
//������
void task1_task(void *pvParameters);

//�������ȼ�
#define TASK2_TASK_PRIO		2
//�����ջ��С	
#define TASK2_STK_SIZE 		128  
//������
TaskHandle_t Task2Task_Handler;
//������
void task2_task(void *pvParameters);

int main(void)
{ 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	delay_init(168);					
	uart_init(115200);    
    xTaskCreate((TaskFunction_t )start_task,           
                (const char*    )"start_task",          
                (uint16_t       )START_STK_SIZE,       
                (void*          )NULL,                
                (UBaseType_t    )START_TASK_PRIO,      
                (TaskHandle_t*  )&StartTask_Handler);         
    vTaskStartScheduler();        
}

//��ʼ����������
void start_task(void *pvParameters)
{
    taskENTER_CRITICAL();           //�����ٽ���
    //����TASK1����
    xTaskCreate((TaskFunction_t )task1_task,             
                (const char*    )"task1_task",           
                (uint16_t       )TASK1_STK_SIZE,        
                (void*          )NULL,                  
                (UBaseType_t    )TASK1_TASK_PRIO,        
                (TaskHandle_t*  )&Task1Task_Handler);   
    //����TASK2����
    xTaskCreate((TaskFunction_t )task2_task,     
                (const char*    )"task2_task",   
                (uint16_t       )TASK2_STK_SIZE,
                (void*          )NULL,
                (UBaseType_t    )TASK2_TASK_PRIO,
                (TaskHandle_t*  )&Task2Task_Handler); 
    vTaskDelete(StartTask_Handler); //ɾ����ʼ����
    taskEXIT_CRITICAL();            //�˳��ٽ���
}



void task1_task(void *pvParameters)
{
	
	while(1)
	{
		
	}
}

void task2_task(void *pvParameters)
{
	
	while(1)
	{
		
	}
}


