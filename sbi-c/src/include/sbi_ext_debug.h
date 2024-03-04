#ifndef __SBI_EXT_DEBUG_H
#define __SBI_EXT_DEBUG_H

//此文件是用户可以调用的API头文件
//包含了调试控制台扩展的SBI调用的C形式的接口
//同时具体定义了对返回值结构体sbi_ret_t 中的value和error 的解释
//以及一些调试控制台扩展需要传入参数的宏定义解释

#include "sbi.h"

/**************************************************************************************************************************************
 * function     :   sbi_debug_console_write                                                                                           *
 * description  :   从输入存储器向调试控制台写入字节                                                                                    *
 * param        :   num_bytes     -> 从输入存储器写入的字节数                                                                           *
 *                  base_addr_lo  -> 输入存储器物理基址低XLEN位                                                                         *
 *                  base_addr_hi  -> 输入存储器物理基址高XLEN位                                                                         *
 * return       :   sbi_ret_t.error  ->错误码                                                                                          *
 *                  sbi_ret_t.value  ->写入的字节数                                                                                    *
 ***********************************************************解释************************************************************************
 *          返回值中 sbi_debug_console_write 对应解释                                                                                   *
 ***************************************************************************************************************************************
 *  SBI_SUCCESS	            成功写入的字节数                                                                                            *
 *  SBI_ERR_INVALID_PARAM	num_bytes、base_addr_lo、base_addr_hi 参数所指向的内存不满足以下条件                                         *
 *                          (1)SBI 实现必须检查监管模式软件是否允许使用请求的访问类型（读和/或写）访问指定的物理内存范围。                   *
 *                          (2)SBI 实现必须使用 PMA 属性访问指定的物理内存范围。                                                          *
 *                          (3)在共享内存中的数据必须遵循小端字节顺序。                                                                   *
 *  SBI_ERR_FAILED	        由于 I/O 错误，写入失败                                                                                      *
 ***************************************************************************************************************************************/
sbi_ret_t sbi_debug_console_write(unsigned long num_bytes,   unsigned long base_addr_lo,   unsigned long base_addr_hi);


#endif