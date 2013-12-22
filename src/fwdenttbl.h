#include <cstdio>
#include <cstdlib>

// 转发表项
struct FwdEnt
{
  int ne_phyid;
  int gne_phyid;
  string ne_ipaddr;
  string gne_ipaddr;
};

// 转发表
class FwdEntTbl
{
  vector<FwdEnt*> m_fwdenttbl;	// 转发表
  // fstream m_file;		// 转发表保存到文件
  // map<string, vector<FwdEnt*>::iterator> m_neipaddrMap;
  
  // 单件类不允许外部创建
  FwdEntTbl();
  FwdEntTbl(const FwdEnt& rhs);
  FwdEntTbl& operator=(const FwdEnt& rhs);
  
public:
  FwdEntTbl();
  ~FwdEntTbl();

  void init();
  void fini();

  static FwdEntTbl* Instance();

  // 根据网元ip地址查询对应表项
  bool getFwdEnt(const char* ne_ipaddr, int& ne_phyid, string& gne_ipaddr, int& gne_phyid);

  // 添加转发表项
  bool addFwdEnt(const char* ne_ipaddr, int ne_phyid, const char* gne_ipaddr, int gne_phyid);

  // 删除转发表项
  bool delFwdEnt(const char* ne_ipaddr);

  // 持久化转发表
  bool save();
};
