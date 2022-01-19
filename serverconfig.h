/*
 * @Author: HK560
 * @Date: 2022-01-14 19:06:51
 * @LastEditTime: 2022-01-19 11:13:02
 * @LastEditors: HK560
 * @Description:
 * @FilePath: \NorthStarCN_WIKIh:\github\ttf\NorthStarServerSetting\serverconfig.h
 * \NorthStarCN_WIKIh:\github\ttf\NorthStarServerSetting\serverconfig.h
 */
#ifndef SERVERCONFIG_H
#define SERVERCONFIG_H
#include<QString>
#include<QVector>
#include<QFileInfo>
#include<QStringList>
#include<qDebug>
#include<QTextCodec>
#include <QRegularExpression>
#include <QRegExp>
#include<QMap>
#include<QSettings>

class ServerConfig {
   public:
   ServerConfig();
   
   QMap<QString,QString> cliMap;
   
   bool writeToCfg();//写入到autoexec_ns_server.cfg
   bool readFromCfg();//读取autoexec_ns_server.cfg
   bool writeToSaveFile(QFileInfo file);//写入到保存的配置文件
   bool readFromSaveFile(QFileInfo file);//读入到保存的配置文件
   bool setConfigValue(QString name,QString value);
   void setFilePath(QFileInfo path);
   void configReset();
   // 写入配置文件的信息
   // QString ns_server_name="[CN]Server";//服务器名称
   // QString ns_server_desc="Welcome everyone";//服务器描述
   // QString ns_server_password="";//服务器密码,为空则没有

   // bool ns_report_server_to_masterserver=true; //服務器是否報告給MasterServer
   // bool ns_report_sp_server_to_masterserver=false;// 服務器是否報告給MasterServer,在單人模式

   // bool ns_auth_allow_insecure=false;// 允许客户端在不使用主服务器进行身份验证的情况下加入您的服务器。主服务器目前是允许客户端直接连接到您的IP而不是通过服务器列表进行验证
   // bool ns_erase_auth_info=true; // 您的服务器是否应该在使用身份验证信息后清除该验证信息，这对于游戏开发非常有帮助，但通常应保持为1
   
   // int ns_player_auth_port=8081;  // 用于服务器本地身份验证服务器的端口，这是我们前面转发的TCP端口,確保是TCP協議
  
   // QString ns_masterserver_hostname="tf2cn.wolf109909.top"; //主服务器域名
  
   // bool everything_unlocked=true; //解锁所有东西
   // bool ns_should_return_to_lobby=true;//比赛结束是否返回大厅
  
   // int net_chan_limit_mode=2;// 如果为0，则不限制单个客户端的网络通道处理时间。如果为1，则踢出超时的客户端。如果为2，则在控制台中记录超时的客户端
   // int net_chan_limit_msec_per_sec=100; // 在net_chan_limit_模式下触发响应之前，客户端每秒可以使用的服务器网络通道处理时间的毫秒数
   // int sv_querylimit_per_sec=15; // 客户端每秒可以发送到此服务器而不会被阻止的无连接数据包的数量
   // double base_tickinterval_mp=0.016667; // 在服务器上运行每个tick之间的延迟，tickrate将为1除以该值
   // int sv_updaterate_mp=20; // 服务器每秒向已连接的玩家发送信息的最大次数，如果玩家的cl_updaterate_mp值低于服务器的数值，则其速率与服务器同步
   // int sv_minupdaterate=20; // unsure if this actually works, but if it does, should set minimum client updaterate
   // int sv_max_snapshots_multiplayer=300; // this needs to be updaterate * 15, or clients will dc in killreplay
   // bool net_data_block_enabled=false; // not really sure on this, have heard datablock could have security issues? doesn't seem to have any adverse effects being disabled
   // bool host_skip_client_dll_crc=true; // allow people to run modded client dlls, this is mainly so people running pilot visor colour mods can keep those, since they use a client.dll edit
   
   private:
   QFileInfo filePath;
};


const QStringList cliStringList={
      "ns_server_name",
      "ns_server_desc",
      "ns_server_password",
      // "ns_report_server_to_masterserver",
      // "ns_report_sp_server_to_masterserver",
      // "ns_auth_allow_insecure",
      // "ns_erase_auth_info",
      // "ns_player_auth_port",
      "ns_masterserver_hostname",
      // "everything_unlocked",
      // "ns_should_return_to_lobby",
      // "net_chan_limit_mode",
      // "net_chan_limit_msec_per_sec",
      // "sv_querylimit_per_sec",
      // "base_tickinterval_mp",
      // "sv_updaterate_mp",
      // "sv_minupdaterate",
      // "sv_max_snapshots_multiplayer",
      // "net_data_block_enabled",
      // "host_skip_client_dll_crc"
   };



#endif  // SERVERCONFIG_H

