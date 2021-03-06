/*------------------------------- include --------------------------------------------------*/
#include "Ctrl_RUDDER.h"
#include "Init_USART.h"
#include "Init_PWM.h"

/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::;
*
*       Programs function: Control steering engines according to the datas from serial port
*       Functions name: Ctrl_RUDDER(u8 uart_rx)         Control steering engines and motor by change PWM signals
*                                     Reset_Vehicle(void)                  Reset all of vehicle's rudders and stop the motor
*
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::;*/
/* Define parameters -------------------------------------------------------------*/
extern float DutyfactorSet_LEFT_UP;
extern float DutyfactorSet_RIGHT_UP;
extern float DutyfactorSet_LEFT_DOWN;
extern float DutyfactorSet_RIGHT_DOWN;
extern float DutyfactorSet_HORIZ_LEFT;
extern float DutyfactorSet_HORIZ_RIGHT;
extern float DutyfactorSet_MOTOR;

//extern u8 ReceiveBuf[UART1_BUF_SIZE];	//Receive data temp buffer area


/*--------------------------- Submarine Reset ---------------------------------*/
//void Reset_Vehicle(void)
//{
//        DutyfactorSet_LEFT_UP = DutyfactorM;
//        DutyfactorSet_RIGHT_UP = DutyfactorM;
//        DutyfactorSet_LEFT_DOWN = DutyfactorM;
//        DutyfactorSet_RIGHT_DOWN = DutyfactorM;
//        DutyfactorSet_HORIZ_LEFT = DutyfactorM;
//        DutyfactorSet_HORIZ_RIGHT = DutyfactorM;
//        DutyfactorSet_MOTOR = DutyfactorMo;
//}

/*--------------------------- Steering Engines Control ---------------------------------*/
//num: Channel number of PWM signals
void Ctrl_RUDDER(u8 num, double pwmBuf)
{
        switch (num)
        {
                case 1:
												if(DutyfactorSet_LEFT_UP < (180 - pwmBuf - bb) * kk / aa)
                        {
                                DutyfactorSet_LEFT_UP += dutyfactor_change;
                                TIM_SetCompare1(TIM4, DutyfactorSet_LEFT_UP);
                                if (DutyfactorSet_LEFT_UP >= (180 - pwmBuf - bb) * kk / aa)
                                {
                                        DutyfactorSet_LEFT_UP = (180 - pwmBuf - bb) * kk / aa;
                                        TIM_SetCompare1(TIM4, DutyfactorSet_LEFT_UP);
                                }
                        }
                         else if(DutyfactorSet_LEFT_UP > (180 - pwmBuf - bb) * kk / aa)
                        {
                                DutyfactorSet_LEFT_UP -= dutyfactor_change;
                                TIM_SetCompare1(TIM4, DutyfactorSet_LEFT_UP);
                                 if (DutyfactorSet_LEFT_UP <= (180 - pwmBuf - bb) * kk / aa)
                                 {
                                        DutyfactorSet_LEFT_UP = (180 - pwmBuf - bb) * kk / aa;
                                        TIM_SetCompare1(TIM4, DutyfactorSet_LEFT_UP);
                                 }
                        }
                        else { }
                        break;
                        
                case 2:
                        if(DutyfactorSet_RIGHT_UP < (180 - pwmBuf - bb) * kk / aa)
                        {
                                DutyfactorSet_RIGHT_UP += dutyfactor_change;
                                TIM_SetCompare2(TIM4, DutyfactorSet_RIGHT_UP);
                                if (DutyfactorSet_RIGHT_UP >= (180 - pwmBuf - bb) * kk / aa)
                                {
                                        DutyfactorSet_RIGHT_UP = (180 - pwmBuf - bb) * kk / aa;
                                        TIM_SetCompare2(TIM4, DutyfactorSet_RIGHT_UP);
                                }
                        }
                        else if(DutyfactorSet_RIGHT_UP > (180 - pwmBuf - bb) * kk / aa)
                        {
                                DutyfactorSet_RIGHT_UP -= dutyfactor_change;
                                TIM_SetCompare2(TIM4, DutyfactorSet_RIGHT_UP);
                                 if (DutyfactorSet_RIGHT_UP <= (180 - pwmBuf - bb) * kk / aa)
                                 {
                                        DutyfactorSet_RIGHT_UP = (180 - pwmBuf - bb) * kk / aa;
                                        TIM_SetCompare2(TIM4, DutyfactorSet_RIGHT_UP);
                                 }
                        }
                        else { }
                        break;
                        
                case 3:
                        if(DutyfactorSet_LEFT_DOWN < (pwmBuf - bb) * kk / aa)
                        {
                                DutyfactorSet_LEFT_DOWN += dutyfactor_change;
                                TIM_SetCompare3(TIM4, DutyfactorSet_LEFT_DOWN);
                                if (DutyfactorSet_LEFT_DOWN >= (pwmBuf - bb) * kk / aa)
                                {
                                        DutyfactorSet_LEFT_DOWN = (pwmBuf - bb) * kk / aa;
                                        TIM_SetCompare3(TIM4, DutyfactorSet_LEFT_DOWN);
                                }
                        }
                        else if(DutyfactorSet_LEFT_DOWN > (pwmBuf - bb) * kk / aa)
                        {
                                DutyfactorSet_LEFT_DOWN -= dutyfactor_change;
                                TIM_SetCompare3(TIM4, DutyfactorSet_LEFT_DOWN);
                                 if (DutyfactorSet_LEFT_DOWN <= (pwmBuf - bb) * kk / aa)
                                 {
                                        DutyfactorSet_LEFT_DOWN = (pwmBuf - bb) * kk / aa;
                                        TIM_SetCompare3(TIM4, DutyfactorSet_LEFT_DOWN);
                                 }
                        }
                        else { }
                        break;
                        
                case 4:
                        if(DutyfactorSet_RIGHT_DOWN < (pwmBuf - bb) * kk / aa)
                        {
                                DutyfactorSet_RIGHT_DOWN += dutyfactor_change;
                                TIM_SetCompare4(TIM4, DutyfactorSet_RIGHT_DOWN);
                                if (DutyfactorSet_RIGHT_DOWN >= (pwmBuf - bb) * kk / aa)
                                {
                                        DutyfactorSet_RIGHT_DOWN = (pwmBuf - bb) * kk / aa;
                                        TIM_SetCompare4(TIM4, DutyfactorSet_RIGHT_DOWN);
                                }
                        }
                        else if(DutyfactorSet_RIGHT_DOWN > (pwmBuf - bb) * kk / aa)
                        {
                                DutyfactorSet_RIGHT_DOWN -= dutyfactor_change;
                                TIM_SetCompare4(TIM4, DutyfactorSet_RIGHT_DOWN);
                                 if (DutyfactorSet_RIGHT_DOWN <= (pwmBuf - bb) * kk / aa)
                                 {
                                        DutyfactorSet_RIGHT_DOWN = (pwmBuf - bb) * kk / aa;
                                        TIM_SetCompare4(TIM4, DutyfactorSet_RIGHT_DOWN);
                                 }
                        }
                        else { }
                        break;
                        
                case 5:
                        if(DutyfactorSet_HORIZ_LEFT < (pwmBuf - bb) * kk / aa)
                        {
                                DutyfactorSet_HORIZ_LEFT += dutyfactor_change;
                                TIM_SetCompare1(TIM3, DutyfactorSet_HORIZ_LEFT);
                                if (DutyfactorSet_HORIZ_LEFT >= (pwmBuf - bb) * kk / aa)
                                {
                                        DutyfactorSet_HORIZ_LEFT = (pwmBuf - bb) * kk / aa;
                                         TIM_SetCompare1(TIM3, DutyfactorSet_HORIZ_LEFT);
                                }
                        }
                        else if(DutyfactorSet_HORIZ_LEFT > (pwmBuf - bb) * kk / aa)
                        {
                                DutyfactorSet_HORIZ_LEFT -= dutyfactor_change;
                                TIM_SetCompare1(TIM3, DutyfactorSet_HORIZ_LEFT);
                                 if (DutyfactorSet_HORIZ_LEFT <= (pwmBuf - bb) * kk / aa)
                                 {
                                        DutyfactorSet_HORIZ_LEFT = (pwmBuf - bb) * kk / aa;
                                          TIM_SetCompare1(TIM3, DutyfactorSet_HORIZ_LEFT);
                                 }
                        }
                        else { }
                        break;
                        
                case 6:
                        if(DutyfactorSet_HORIZ_RIGHT < (180 - pwmBuf - bb) * kk / aa)
                        {
                                DutyfactorSet_HORIZ_RIGHT += dutyfactor_change;
                                TIM_SetCompare2(TIM3, DutyfactorSet_HORIZ_RIGHT);
                                if (DutyfactorSet_HORIZ_RIGHT >= (180 - pwmBuf - bb) * kk / aa)
                                {
                                        DutyfactorSet_HORIZ_RIGHT = (180 - pwmBuf - bb) * kk / aa;
                                        TIM_SetCompare2(TIM3, DutyfactorSet_HORIZ_RIGHT);
                                }
                        }
                        else if(DutyfactorSet_HORIZ_RIGHT > (180 - pwmBuf - bb) * kk / aa)
                        {
                                DutyfactorSet_HORIZ_RIGHT -= dutyfactor_change;
                                TIM_SetCompare2(TIM3, DutyfactorSet_HORIZ_RIGHT);
                                 if (DutyfactorSet_HORIZ_RIGHT <= (180 - pwmBuf - bb) * kk / aa)
                                 {
                                        DutyfactorSet_HORIZ_RIGHT = (180 - pwmBuf - bb) * kk / aa;
                                        TIM_SetCompare2(TIM3, DutyfactorSet_HORIZ_RIGHT);
                                 }
                        }
                        else { }
                        break;
        }
}

/*--------------------------- Motor Control ---------------------------------*/
//speed: PWM signal
 void Ctrl_MOTOR(double speed)     //Motor control PWM
{
        TIM_SetCompare3(TIM3, speed * (20000.0 / 1000.0));
}










