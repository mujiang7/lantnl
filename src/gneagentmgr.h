#include <cstdio>

#define AGENT_LIMIT 64 		// 最大支持代理进程个数

struct GneAgent {
  pid_t pid;			// 处理这个GNE通信的子进程id
  int wpipefd[2];		// 父进程给这个子进程写数据的管道
  int rpipefd[2];		// 父进程从子进程读数据读数据的管道
  vector<string> gnelist;	// 此子进程中的网关网元ip地址列表
};

class GneAgentMgr
{
  vector<GneAgent*> m_gnelist;	// 子进程列表
public:
  GneAgentMgr();
  virtual ~GneAgentMgr();
  // 
  void startAgent(GneAgent* agent);
  // 
  void stopAgent(pid_t pid);

  // 查询指定的ne ip地址所在的进程id
  pid_t getProcessOfNe(const char* ne_ipaddr);
  // 查询制定的gne ip地址所在的进程id
  pid_t getProcessOfGne(const char* gne_ipaddr);

  // 获取指定ne ip地址的写管道描述符
  int getFdOfNe(const char* ne_ipaddr);
};

