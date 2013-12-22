#!env perl -w
use strict;
use warnings;

use Linux::TunTap;

$| = 1;
my $tun = new Linux::TunTap;
my $ifname = $tun->{interface};

if ($tun) {
  print "$ifname interface created\n";

  system "ifconfig $ifname 10.0.0.1 netmask 255.0.0.0 mtu 908";
}

while (my $packet=$tun->get_raw()) {
  # print_ippacket($packet);
  dump_ippacket($packet);
}

sub dump_ippacket {
  print "========begin dump========";
  my $packet = shift;
  my $len = length $packet;
  for (0..$len) {
    if ($_ % 32 == 0) {
      print "\n";
    }
    printf "%02X ", ord(substr($packet, $_, 1));
  }
  print "\n";
  print "========end dump========\n";
}
sub print_ippacket {
  my $packet = shift;
  my $len = length $packet;
  my $offset = 0;

  # print "sk_buff: ", substr($packet, 0, 4), "\n";
  my $ippacket = substr($packet, 4, $len - 4);
  my ($ipv, $iptos, $plen) = unpack("BBS",substr($ippacket, 0, 4));
  print "ipversion:$ipv iptos:$iptos length:$plen\n";
  my ($ttl,$ptype) = unpack("BB", substr($ippacket, 8, 2));
  print "ttl:$ttl, pro:$ptype\n";
  my ($src, $snk) = unpack("NN", substr($ippacket, 12, 8));
  print "src:$src, snk:$snk\n";
}
