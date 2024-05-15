/*
 * bit.h
 *
 * Created: 05/12/2022 15:48:38
 *  Author: hala
 */ 


#ifndef BIT_H_
#define BIT_H_

#define SET_BIT(REG,BIT) 	REG|=(1<<BIT)
#define GET_BIT(REG,BIT) 	((REG>>BIT) & 1)
#define CLR_BIT(REG,BIT)	REG&=~(1<<BIT)
#define TOGGLE_BIT(REG,BIT) REG^=(1<<BIT)



#endif /* BIT_H_ */