/*
 * base64Impl.h
 *
 *  Created on: 2015-5-14
 *      Author: zhiqiang.lei
 */

#ifndef BASE64IMPL_H_
#define BASE64IMPL_H_

char* base64encode(const char* str);
char* translate3to4(char a,char b,char c);
char* translate3to4(char a,char b);
char* translate3to4(char a);
char num2base64char(char n);
char* translate4to3(char a,char b,char c,char d);
char base64char2num(char b);
char* base64decode(const char* str);

#endif /* BASE64IMPL_H_ */
