#include "DIO_cfg.h"
#include "DIO.h"
void DIO_Init()
{
                                        /**********PORT-A  Pin Configuration***********/

                                                  DIO_Define_Pin(PIN_0A,OUT);
                                                  DIO_Define_Pin(PIN_1A,INup);
                                                  DIO_Define_Pin(PIN_2A,INfree);
                                                  DIO_Define_Pin(PIN_3A,INfree);
                                                  DIO_Define_Pin(PIN_4A,INfree);
                                                  DIO_Define_Pin(PIN_5A,INfree);
                                                  DIO_Define_Pin(PIN_6A,INfree);
                                                  DIO_Define_Pin(PIN_7A,INfree);

                                        /**********PORT-B  Pin Configuration***********/

                                                  DIO_Define_Pin(PIN_0B,INup);
                                                  DIO_Define_Pin(PIN_1B,OUT);
                                                  DIO_Define_Pin(PIN_2B,INfree);
                                                  DIO_Define_Pin(PIN_3B,INfree);
                                                  DIO_Define_Pin(PIN_4B,INfree);
                                                  DIO_Define_Pin(PIN_5B,INfree);
                                                  DIO_Define_Pin(PIN_6B,INfree);
                                                  DIO_Define_Pin(PIN_7B,INfree);

                                       /************PORT-C Pin Configuration***********/

                                                  DIO_Define_Pin(PIN_0C,INup);
                                                  DIO_Define_Pin(PIN_1C,INfree);
                                                  DIO_Define_Pin(PIN_2C,OUT);
                                                  DIO_Define_Pin(PIN_3C,INfree);
                                                  DIO_Define_Pin(PIN_4C,INfree);
                                                  DIO_Define_Pin(PIN_5C,INfree);
                                                  DIO_Define_Pin(PIN_6C,INfree);
                                                  DIO_Define_Pin(PIN_7C,INfree);

                                        /***********PORT-D  Pin Configuration**********/

                                                   DIO_Define_Pin(PIN_0D,INup);
                                                   DIO_Define_Pin(PIN_1D,INfree);
                                                   DIO_Define_Pin(PIN_2D,INfree);
                                                   DIO_Define_Pin(PIN_3D,OUT);
                                                   DIO_Define_Pin(PIN_4D,INfree);
                                                   DIO_Define_Pin(PIN_5D,INfree);
                                                   DIO_Define_Pin(PIN_6D,INup);
                                                   DIO_Define_Pin(PIN_7D,INfree);

}