#include <cstdio>

void process_option(int, char**);
void init_env();
void init_tun();
void init_fwdenttbl();
void init_agent();

int main(int argc, char *argv[])
{
  process_option(argc, argv);
  init_env();
  init_fwdenttbl();
  init_tun();
  init_agent();

  while(1) {
    Reactor::Instance()->start_event();
  }
  return 0;
}

