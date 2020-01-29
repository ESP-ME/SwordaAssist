# 月影传说辅助


#### 介绍
  月影传说是由金山制作发行的一款单机版ARPG游戏，发行于2001年。该辅助程序可以修改人物等级，防御力，攻击力，身法，生命，体力，内力和金钱基本属性，并实现自动增加生命值，体力和内力功能，后期将会增加学习技能功能和修改技能等级功能。 **喜欢请给个Star和fork** 

#### 实现原理
1. 辅助程序启动游戏进程后在访问人物等级的地址打断点，即0x004060CC位置打断点（后来调试发现访问其他属性地址时esi是一样的，所以在其他位置就不用打断点了，其他属性访问地址可以查看下面的#define）。
2. 游戏线程运行到断点位置后暂停运行，辅助程序将获取游戏控制权。
3. 辅助程序记录当前esi的值(当前esi的值是访问英雄属性的基地址，其实获取esi的值后就可以直接对英雄属性读写了可以不用注入代码如步骤4和步骤5，这样实现更简单)。
4. 辅助程序注入修改属性代码且在注入代码结束位置再次打断点，之后恢复游戏线程。
5. 游戏线程恢复执行,执行注入代码,由于注入代码后面有断点执行完注入代码后游戏线程再次被暂停运行，辅助程序再次获取游戏控制权恢复旧代码，并把eip指向旧代码开始位置后恢复游戏线程，这时英雄属性就被注入代码修改了。
6. 辅助程序启动监控线程通过esi+偏移读取英雄当前生命，体力，内力，当英雄当前生命，体力，内力减少到一定值时再往内存加数值就可以了。

  有程序上的问题可以扫码向我提问，在下方就不进行回复了

![输入图片说明](https://images.gitee.com/uploads/images/2019/0909/134631_0454b2a5_1650820.png "微信扫码.png")

访问人物属性的地址：

#define ACCESS_GRADE_ADDRESS   0x004060CC             //访问等级代码地址，所在地址代码：mov edx,[esi+0x004DECF8] 

#define ACCESS_DEFENSE_ADDRESS 0x00406166             //访问防御力代码地址，所在地址代码：mov eax,[esi+0x004DECF0] 

#define ACCESS_AGGRESSIVITY_ADDRESS 0x00406154        //访问攻击力代码地址，所在地址代码：mov edx,[esi+0x004DECEC] 

#define ACCESS_POSITIONING_ADDRESS 0x00406178         //访问身法代码地址，所在地址代码：mov ecx,[esi+0x004DECF4] 

#define ACCESS_CURRENT_LIFE_ADDRESS 0x0040220B        //访问英雄当前生命代码地址，所在地址代码：mov eax,[esi+0x004DECD4] 
                          
#define ACCESS_LIFE_ADDRESS  0x00402205               //访问生命代码地址，所在地址代码：mov ecx,[esi+0x004DECD8] 

#define ACCESS_CURRENT_STRENGTH_ADDRESS 0x0040221E    //访问英雄当前体力代码地址，所在地址代码：mov edx,[esi+0x004DECDC] 

#define ACCESS_STRENGTH_ADDRESS 0x00402218            //访问体力代码地址，所在地址代码：mov edx,[esi+0x004DECE0] 

#define ACCESS_CURRENT_INTERNALFORCE_ADDRESS 0x00402250 //访问英雄当前内力代码地址，所在地址代码：mov ecx,[esi+0x004DECE4] 

#define ACCESS_INTERNALFORCE_ADDRESS 0x0040224A       //访问内力代码地址，所在地址代码：mov eax,[esi+0x004DECE8] 

#define ACCESS_MONEY_ADDRESS 0x00402FE9               //访问金钱代码地址，所在地址代码：mov eax,[0x0055d1c4](金钱访问地址是固定的)

#### 软件架构
开发语言: C/C++

开发环境: Win 10

开发工具：Visual Studio 2017



#### 安装教程
0x01 到/Release/目录下运行SwordaAssist.exe即可，也可以将工程导入VS 2017自己编译  **(注意:需关闭360或添加信任，因为本程序会对游戏进程进行读写和修改，会被360误认为是木马)** 

![输入图片说明](https://images.gitee.com/uploads/images/2019/0908/222821_91674c4f_1650820.png "认为是木马.png")

0x02 月影传说游戏安装包可以到 http://www.downza.cn/soft/223529.html 下载

#### 使用说明

 **0x01  到/Release/目录下运行SwordaAssist.exe打开辅助** 
![输入图片说明](https://images.gitee.com/uploads/images/2019/0908/221611_55b7ad01_1650820.png "1.打开辅助.png")

 **0x02  运行游戏** 
![输入图片说明](https://images.gitee.com/uploads/images/2019/0908/221620_b865ff70_1650820.png "2.运行游戏.png")

 **0x03  进入到游戏界面后切换到辅助界面(ALT+TAB和Window键都可以切换)** 
![输入图片说明](https://images.gitee.com/uploads/images/2019/0908/221635_4719abcd_1650820.png "3.进入到游戏界面后切换到辅助界面(ALT+TAB).png")

 **0x04  设置要修改的任务属性和其他功能然后保存修改** 
![输入图片说明](https://images.gitee.com/uploads/images/2019/0908/221648_8644496d_1650820.png "4.设置要修改的任务属性和其他功能然后保存修改.png")

 **0x05  切换到游戏界面这时英雄的等级，防御力，攻击力，身法，生命，体力，内力和金钱属性已修改，并且生命，体力，内力过低时会自动增加** 

![输入图片说明](https://images.gitee.com/uploads/images/2019/0908/221705_62273c39_1650820.png "5.切换到游戏界面这时英雄属性已修改.png")

 **_注意：主角下山后到武当山和张惟宜挑战时一定不要设置属性太变态，因为剧情安排这次比武是主角是输的，如果赢了主角就会自杀 :joy: _** 

![输入图片说明](https://images.gitee.com/uploads/images/2019/0917/203625_1918b962_1650820.png "QQ截图20190902220436.png")
![输入图片说明](https://images.gitee.com/uploads/images/2019/0917/203653_31c84be1_1650820.png "2.png")
![输入图片说明](https://images.gitee.com/uploads/images/2019/0917/203705_f181adae_1650820.png "QQ截图20190902220609.png")


#### 参与贡献

1. Fork 本仓库
2. 新建 Feat_xxx 分支
3. 提交代码
4. 新建 Pull Request


#### 码云特技

1. 使用 Readme\_XXX.md 来支持不同的语言，例如 Readme\_en.md, Readme\_zh.md
2. 码云官方博客 [blog.gitee.com](https://blog.gitee.com)
3. 你可以 [https://gitee.com/explore](https://gitee.com/explore) 这个地址来了解码云上的优秀开源项目
4. [GVP](https://gitee.com/gvp) 全称是码云最有价值开源项目，是码云综合评定出的优秀开源项目
5. 码云官方提供的使用手册 [https://gitee.com/help](https://gitee.com/help)
6. 码云封面人物是一档用来展示码云会员风采的栏目 [https://gitee.com/gitee-stars/](https://gitee.com/gitee-stars/)