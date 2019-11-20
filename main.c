/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.155.0-a
        Device            :  dsPIC33CK256MP508
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.40
        MPLAB 	          :  MPLAB X v5.25
*/

/*
    (c) 2019 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "string.h"

/*
                         Main application
 */
int main(void)
{
    char tempstring[100];
    int tempstring_length = 0;
    char command[100];
    int command_value;
    // initialize the device
    SYSTEM_Initialize();
    SCCP1_CAPTURE_Start();
    printf("Hello \r\n");
    while (1)
    {
        if (UART1_IsRxReady()) {
            uint8_t temp = UART1_Read();
            if (temp == 13) {
                printf("OMG! You pressed Enter!\r\n");
                if (strcmp(tempstring,"Jonathan")==0) {
                    printf("That's one cool guy!\r\n");
                }
                if (sscanf(tempstring,"%s %d", command, &command_value)==2) {
                    printf("You've sent command %s",command);
                    printf(" with value %d\r\n",command_value);
                }
                tempstring[tempstring_length] = 0;
                printf(tempstring);
                printf("\r\n");
                tempstring_length = 0;
            }else{
                tempstring[tempstring_length++] = temp;
                printf("Just got %d \r\n",temp);
                printf("%c",temp);
            }
        }
        if (!SCCP1_CAPTURE_IsBufferEmpty()) {
            printf("Got an event at %d \r\n",SCCP1_CAPTURE_Data32Read());
        }
    }
    return 1; 
}
/**
 End of File
*/

