#pragma once
#include "stdafx.h"

#define OPERATE_STATE_REQUEST_MODIFY_SPIRIT                  (UINT)1
#define OPERATE_STATE_BREAKPOINT_MODIFY_SPIRIT        (UINT)2
#define OPERATE_STATE_MODIFYING_SPIRIT                (UINT)3
#define OPERATE_STATE_FINISH_MODIFY_SPIRIT            (UINT)4

#define OPERATE_STATE_REQUEST_MODIFY_SPIRIT_GRADE     (UINT)5                  //修改英雄等级属性(待完成)  
#define OPERATE_STATE_BREAKPOINT_MODIFY_SPIRIT_GRADE  (UINT)6                 //修改英雄等级属性(打断点)  
#define OPERATE_STATE_MODIFYING_SPIRIT_GRADE          (UINT)7                //修改英雄等级属性(修改中) 
#define OPERATE_STATE_FINISH_MODIFY_SPIRIT_GRADE      (UINT)8               //修改英雄等级属性(已完成)  
 

#define OPERATE_STATE_REQUEST_MODIFY_SPIRIT_DEFENSE    (UINT)9                    //修改英雄防御力属性(待完成)  
#define OPERATE_STATE_BREAKPOINT_MODIFY_SPIRIT_DEFENSE (UINT)10                   //修改英雄防御力属性(打断点)
#define OPERATE_STATE_MODIFYING_SPIRIT_DEFENSE         (UINT)11                  //修改英雄防御力属性(修改中) 
#define OPERATE_STATE_FINISH_MODIFY_SPIRIT_DEFENSE     (UINT)12                 //修改英雄防御力属性(已完成)  
 

#define OPERATE_STATE_REQUEST_MODIFY_SPIRIT_AGGRESSIVITY     (UINT)13                    //修改英雄攻击力属性(待完成)  
#define OPERATE_STATE_BREAKPOINT_SPIRIT_AGGRESSIVITY         (UINT)14                   //修改英雄攻击力属性(打断点)
#define OPERATE_STATE_MODIFYING_SPIRIT_AGGRESSIVITY          (UINT)15                  //修改英雄攻击力属性(修改中) 
#define OPERATE_STATE_FINISH_MODIFY_SPIRIT_AGGRESSIVITY      (UINT)16                 //修改英雄攻击力属性(已完成)  
 

#define OPERATE_STATE_REQUEST_MODIFY_SPIRIT_POSITIONING     (UINT)17                   //修改英雄身法属性(待完成)  
#define OPERATE_STATE_BREAKPOINT_SPIRIT_POSITIONING         (UINT)18                  //修改英雄身法属性(打断点)
#define OPERATE_STATE_MODIFYING_SPIRIT_POSITIONING          (UINT)19                 //修改英雄身法属性(修改中)  
#define OPERATE_STATE_FINISH_MODIFY_SPIRIT_POSITIONING      (UINT)20                //修改英雄身法属性(已完成)  


#define OPERATE_STATE_REQUEST_MODIFY_SPIRIT_LIFE     (UINT)21                   //修改英雄生命属性(待完成)  
#define OPERATE_STATE_BREAKPOINT_MODIFY_SPIRIT_LIFE  (UINT)22                  //修改英雄生命属性(打断点)
#define OPERATE_STATE_MODIFYING_SPIRIT_LIFE          (UINT)23                 //修改英雄生命属性(修改中) 
#define OPERATE_STATE_FINISH_MODIFY_SPIRIT_LIFE      (UINT)24                //修改英雄生命属性(已完成)  
 

#define OPERATE_STATE_REQUEST_MODIFY_SPIRIT_STRENGTH     (UINT)25                  //修改英雄体力属性(待完成)  
#define OPERATE_STATE_BREAKPOINT_SPIRIT_STRENGTH         (UINT)26                 //修改英雄体力属性(打断点)
#define OPERATE_STATE_MODIFYING_SPIRIT_STRENGTH          (UINT)27                //修改英雄体力属性(修改中)
#define OPERATE_STATE_FINISH_MODIFY_SPIRIT_STRENGTH      (UINT)28               //修改英雄体力属性(已完成)  
  

#define OPERATE_STATE_REQUEST_MODIFY_SPIRIT_INTERNALFORCE     (UINT)29                  //修改英雄内力属性(待完成)  
#define OPERATE_STATE_BREAKPOINT_MODIFY_SPIRIT_INTERNALFORCE  (UINT)30                 //修改英雄内力属性(打断点) 
#define OPERATE_STATE_MODIFYING_SPIRIT_INTERNALFORCE          (UINT)31                //修改英雄内力属性(修改中)  
#define OPERATE_STATE_FINISH_MODIFY_SPIRIT_INTERNALFORCE      (UINT)32               //修改英雄内力属性(已完成)  


#define OPERATE_STATE_REQUEST_MODIFY_SPIRIT_MONEY     (UINT)33                   //修改英雄金钱属性(待完成)  
#define OPERATE_STATE_BREAKPOINT_MODIFY_SPIRIT_MONEY  (UINT)34                  //修改英雄金钱属性(打断点) 
#define OPERATE_STATE_FINISH_MODIFY_SPIRIT_MONEY      (UINT)35                 //修改英雄金钱属性(已完成)  
#define OPERATE_STATE_MODIFYING_SPIRIT_MONEY          (UINT)36                //修改英雄金钱属性(修改中)  


#define OPERATE_STATE_REQUEST_REFRESH           (UINT)37                 //刷新信息(待完成) 
#define OPERATE_STATE_BREAKPOINT_REFRESH        (UINT)38                 //刷新信息(打断点)
#define OPERATE_STATE_REFRESHING                (UINT)39                 //刷新信息(刷新中)
#define OPERATE_STATE_FINISH_REFRESH            (UINT)40                 //刷新信息(已完成)


#define ACCESS_GRADE_ADDRESS   0x004060CC             //访问等级代码地址           mov edx,[esi+0x004DECF8]
#define ACCESS_DEFENSE_ADDRESS 0x00406166             //访问防御力代码地址         mov eax,[esi+0x004DECF0]
#define ACCESS_AGGRESSIVITY_ADDRESS 0x00406154        //访问攻击力代码地址         mov edx,[esi+0x004DECEC]
#define ACCESS_POSITIONING_ADDRESS 0x00406178         //访问身法代码地址           mov ecx,[esi+0x004DECF4]
#define ACCESS_CURRENT_LIFE_ADDRESS 0x0040220B        //访问英雄当前生命代码地址   mov eax,[esi+0x004DECD4]                          
#define ACCESS_LIFE_ADDRESS  0x00402205               //访问生命代码地址           mov ecx,[esi+0x004DECD8]
#define ACCESS_CURRENT_STRENGTH_ADDRESS 0x0040221E    //访问英雄当前体力代码地址   mov edx,[esi+0x004DECDC]
#define ACCESS_STRENGTH_ADDRESS 0x00402218            //访问体力代码地址           mov edx,[esi+0x004DECE0]
#define ACCESS_CURRENT_INTERNALFORCE_ADDRESS 0x00402250 //访问英雄当前内力代码地址 mov ecx,[esi+0x004DECE4]
#define ACCESS_INTERNALFORCE_ADDRESS 0x0040224A       //访问内力代码地址           mov eax,[esi+0x004DECE8]
#define ACCESS_MONEY_ADDRESS 0x00402FE9               //访问金钱代码地址           mov eax,[0x0055d1c4]  金钱访问地址是固定的



