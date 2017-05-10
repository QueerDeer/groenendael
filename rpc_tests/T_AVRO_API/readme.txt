do not run it by yourself - in case of this special information:

*** Error in `./T_AVRO_API': free(): invalid pointer: 0x00007fce90b02010 ***
======= Backtrace: =========
/lib/x86_64-linux-gnu/libc.so.6(+0x777e5)[0x7fcfa279e7e5]
/lib/x86_64-linux-gnu/libc.so.6(+0x7fe0a)[0x7fcfa27a6e0a]
/lib/x86_64-linux-gnu/libc.so.6(cfree+0x4c)[0x7fcfa27aa98c]
./T_AVRO_API[0x402610]
/lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0xf0)[0x7fcfa2747830]
./T_AVRO_API[0x402a59]
======= Memory map: ========
00400000-00404000 r-xp 00000000 08:01 11936059                           /home/groenendael/rpc_tests/T_AVRO_API/T_AVRO_API
00603000-00604000 r--p 00003000 08:01 11936059                           /home/groenendael/rpc_tests/T_AVRO_API/T_AVRO_API
00604000-00605000 rw-p 00004000 08:01 11936059                           /home/groenendael/rpc_tests/T_AVRO_API/T_AVRO_API
01060000-010dd000 rw-p 00000000 00:00 0                                  [heap]
7fce90b02000-7fceccb03000 rw-p 00000000 00:00 0 
7fcee312b000-7fcf0892c000 rw-p 00000000 00:00 0 
7fcf74000000-7fcf74021000 rw-p 00000000 00:00 0 
7fcf74021000-7fcf78000000 ---p 00000000 00:00 0 
7fcf79330000-7fcf9eb31000 rw-p 00000000 00:00 0 
7fcf9eb31000-7fcf9ef3b000 r--p 00000000 08:01 12320896                   /usr/lib/locale/locale-archive
7fcf9ef3b000-7fcf9efa9000 r-xp 00000000 08:01 786505                     /lib/x86_64-linux-gnu/libpcre.so.3.13.2
7fcf9efa9000-7fcf9f1a9000 ---p 0006e000 08:01 786505                     /lib/x86_64-linux-gnu/libpcre.so.3.13.2
7fcf9f1a9000-7fcf9f1aa000 r--p 0006e000 08:01 786505                     /lib/x86_64-linux-gnu/libpcre.so.3.13.2
7fcf9f1aa000-7fcf9f1ab000 rw-p 0006f000 08:01 786505                     /lib/x86_64-linux-gnu/libpcre.so.3.13.2
7fcf9f1ab000-7fcfa0a61000 r-xp 00000000 08:01 12325052                   /usr/lib/x86_64-linux-gnu/libicudata.so.55.1
7fcfa0a61000-7fcfa0c60000 ---p 018b6000 08:01 12325052                   /usr/lib/x86_64-linux-gnu/libicudata.so.55.1
7fcfa0c60000-7fcfa0c61000 r--p 018b5000 08:01 12325052                   /usr/lib/x86_64-linux-gnu/libicudata.so.55.1
7fcfa0c61000-7fcfa0c62000 rw-p 018b6000 08:01 12325052                   /usr/lib/x86_64-linux-gnu/libicudata.so.55.1
7fcfa0c62000-7fcfa0c71000 r-xp 00000000 08:01 786511                     /lib/x86_64-linux-gnu/libbz2.so.1.0.4
7fcfa0c71000-7fcfa0e70000 ---p 0000f000 08:01 786511                     /lib/x86_64-linux-gnu/libbz2.so.1.0.4
7fcfa0e70000-7fcfa0e71000 r--p 0000e000 08:01 786511                     /lib/x86_64-linux-gnu/libbz2.so.1.0.4
7fcfa0e71000-7fcfa0e72000 rw-p 0000f000 08:01 786511                     /lib/x86_64-linux-gnu/libbz2.so.1.0.4
7fcfa0e72000-7fcfa0f7a000 r-xp 00000000 08:01 786615                     /lib/x86_64-linux-gnu/libm-2.23.so
7fcfa0f7a000-7fcfa1179000 ---p 00108000 08:01 786615                     /lib/x86_64-linux-gnu/libm-2.23.so
7fcfa1179000-7fcfa117a000 r--p 00107000 08:01 786615                     /lib/x86_64-linux-gnu/libm-2.23.so
7fcfa117a000-7fcfa117b000 rw-p 00108000 08:01 786615                     /lib/x86_64-linux-gnu/libm-2.23.so
7fcfa117b000-7fcfa1182000 r-xp 00000000 08:01 786624                     /lib/x86_64-linux-gnu/librt-2.23.so
7fcfa1182000-7fcfa1381000 ---p 00007000 08:01 786624                     /lib/x86_64-linux-gnu/librt-2.23.so
7fcfa1381000-7fcfa1382000 r--p 00006000 08:01 786624                     /lib/x86_64-linux-gnu/librt-2.23.so
7fcfa1382000-7fcfa1383000 rw-p 00007000 08:01 786624                     /lib/x86_64-linux-gnu/librt-2.23.so
7fcfa1383000-7fcfa1492000 r-xp 00000000 08:01 786678                     /lib/x86_64-linux-gnu/libglib-2.0.so.0.4800.2
7fcfa1492000-7fcfa1691000 ---p 0010f000 08:01 786678                     /lib/x86_64-linux-gnu/libglib-2.0.so.0.4800.2
7fcfa1691000-7fcfa1692000 r--p 0010e000 08:01 786678                     /lib/x86_64-linux-gnu/libglib-2.0.so.0.4800.2
7fcfa1692000-7fcfa1693000 rw-p 0010f000 08:01 786678                     /lib/x86_64-linux-gnu/libglib-2.0.so.0.4800.2
7fcfa1693000-7fcfa1694000 rw-p 00000000 00:00 0 
7fcfa1694000-7fcfa1697000 r-xp 00000000 08:01 786613                     /lib/x86_64-linux-gnu/libdl-2.23.so
7fcfa1697000-7fcfa1896000 ---p 00003000 08:01 786613                     /lib/x86_64-linux-gnu/libdl-2.23.so
7fcfa1896000-7fcfa1897000 r--p 00002000 08:01 786613                     /lib/x86_64-linux-gnu/libdl-2.23.so
7fcfa1897000-7fcfa1898000 rw-p 00003000 08:01 786613                     /lib/x86_64-linux-gnu/libdl-2.23.so
7fcfa1898000-7fcfa18fc000 r-xp 00000000 08:01 12323928                   /usr/lib/x86_64-linux-gnu/libpcre16.so.3.13.2
7fcfa18fc000-7fcfa1afc000 ---p 00064000 08:01 12323928                   /usr/lib/x86_64-linux-gnu/libpcre16.so.3.13.2
7fcfa1afc000-7fcfa1afd000 r--p 00064000 08:01 12323928                   /usr/lib/x86_64-linux-gnu/libpcre16.so.3.13.2
7fcfa1afd000-7fcfa1afe000 rw-p 00065000 08:01 12323928                   /usr/lib/x86_64-linux-gnu/libpcre16.so.3.13.2
7fcfa1afe000-7fcfa1c7d000 r-xp 00000000 08:01 12325054                   /usr/lib/x86_64-linux-gnu/libicuuc.so.55.1
7fcfa1c7d000-7fcfa1e7d000 ---p 0017f000 08:01 12325054                   /usr/lib/x86_64-linux-gnu/libicuuc.so.55.1
7fcfa1e7d000-7fcfa1e8d000 r--p 0017f000 08:01 12325054                   /usr/lib/x86_64-linux-gnu/libicuuc.so.55.1
7fcfa1e8d000-7fcfa1e8e000 rw-p 0018f000 08:01 12325054                   /usr/lib/x86_64-linux-gnu/libicuuc.so.55.1
7fcfa1e8e000-7fcfa1e92000 rw-p 00000000 00:00 0 
7fcfa1e92000-7fcfa20e4000 r-xp 00000000 08:01 12325051                   /usr/lib/x86_64-linux-gnu/libicui18n.so.55.1
7fcfa20e4000-7fcfa22e4000 ---p 00252000 08:01 12325051                   /usr/lib/x86_64-linux-gnu/libicui18n.so.55.1
7fcfa22e4000-7fcfa22f3000 r--p 00252000 08:01 12325051                   /usr/lib/x86_64-linux-gnu/libicui18n.so.55.1
7fcfa22f3000-7fcfa22f4000 rw-p 00261000 08:01 12325051                   /usr/lib/x86_64-linux-gnu/libicui18n.so.55.1
7fcfa22f4000-7fcfa230d000 r-xp 00000000 08:01 786840                     /lib/x86_64-linux-gnu/libz.so.1.2.8
7fcfa230d000-7fcfa250c000 ---p 00019000 08:01 786840                     /lib/x86_64-linux-gnu/libz.so.1.2.8
7fcfa250c000-7fcfa250d000 r--p 00018000 08:01 786840                     /lib/x86_64-linux-gnu/libz.so.1.2.8
7fcfa250d000-7fcfa250e000 rw-p 00019000 08:01 786840                     /lib/x86_64-linux-gnu/libz.so.1.2.8
7fcfa250e000-7fcfa2525000 r-xp 00000000 08:01 12327660                   /usr/lib/x86_64-linux-gnu/libboost_iostreams.so.1.58.0
7fcfa2525000-7fcfa2725000 ---p 00017000 08:01 12327660                   /usr/lib/x86_64-linux-gnu/libboost_iostreams.so.1.58.0
7fcfa2725000-7fcfa2726000 r--p 00017000 08:01 12327660                   /usr/lib/x86_64-linux-gnu/libboost_iostreams.so.1.58.0
7fcfa2726000-7fcfa2727000 rw-p 00018000 08:01 12327660                   /usr/lib/x86_64-linux-gnu/libboost_iostreams.so.1.58.0
7fcfa2727000-7fcfa28e6000 r-xp 00000000 08:01 786617                     /lib/x86_64-linux-gnu/libc-2.23.so
7fcfa28e6000-7fcfa2ae6000 ---p 001bf000 08:01 786617                     /lib/x86_64-linux-gnu/libc-2.23.so
7fcfa2ae6000-7fcfa2aea000 r--p 001bf000 08:01 786617                     /lib/x86_64-linux-gnu/libc-2.23.so
7fcfa2aea000-7fcfa2aec000 rw-p 001c3000 08:01 786617                     /lib/x86_64-linux-gnu/libc-2.23.so
7fcfa2aec000-7fcfa2af0000 rw-p 00000000 00:00 0 
7fcfa2af0000-7fcfa2b06000 r-xp 00000000 08:01 786850                     /lib/x86_64-linux-gnu/libgcc_s.so.1
7fcfa2b06000-7fcfa2d05000 ---p 00016000 08:01 786850                     /lib/x86_64-linux-gnu/libgcc_s.so.1
7fcfa2d05000-7fcfa2d06000 rw-p 00015000 08:01 786850                     /lib/x86_64-linux-gnu/libgcc_s.so.1
7fcfa2d06000-7fcfa2e78000 r-xp 00000000 08:01 12327688                   /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.21
7fcfa2e78000-7fcfa3078000 ---p 00172000 08:01 12327688                   /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.21
7fcfa3078000-7fcfa3082000 r--p 00172000 08:01 12327688                   /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.21
7fcfa3082000-7fcfa3084000 rw-p 0017c000 08:01 12327688                   /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.21
7fcfa3084000-7fcfa3088000 rw-p 00000000 00:00 0 
7fcfa3088000-7fcfa30a0000 r-xp 00000000 08:01 786628                     /lib/x86_64-linux-gnu/libpthread-2.23.so
7fcfa30a0000-7fcfa329f000 ---p 00018000 08:01 786628                     /lib/x86_64-linux-gnu/libpthread-2.23.so
7fcfa329f000-7fcfa32a0000 r--p 00017000 08:01 786628                     /lib/x86_64-linux-gnu/libpthread-2.23.so
7fcfa32a0000-7fcfa32a1000 rw-p 00018000 08:01 786628                     /lib/x86_64-linux-gnu/libpthread-2.23.so
7fcfa32a1000-7fcfa32a5000 rw-p 00000000 00:00 0 
7fcfa32a5000-7fcfa376a000 r-xp 00000000 08:01 12328341                   /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.5.1
7fcfa376a000-7fcfa3776000 r--p 004c4000 08:01 12328341                   /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.5.1
7fcfa3776000-7fcfa3777000 rw-p 004d0000 08:01 12328341                   /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.5.1
7fcfa3777000-7fcfa377b000 rw-p 00000000 00:00 0 
7fcfa377b000-7fcfa3871000 r-xp 00000000 08:01 12714283                   /usr/local/lib/libavrocpp.so.1.9.0-SNAPSHOT.0
7fcfa3871000-7fcfa3a71000 ---p 000f6000 08:01 12714283                   /usr/local/lib/libavrocpp.so.1.9.0-SNAPSHOT.0
7fcfa3a71000-7fcfa3a78000 r--p 000f6000 08:01 12714283                   /usr/local/lib/libavrocpp.so.1.9.0-SNAPSHOT.0
7fcfa3a78000-7fcfa3a7a000 rw-p 000fd000 08:01 12714283                   /usr/local/lib/libavrocpp.so.1.9.0-SNAPSHOT.0
7fcfa3a7a000-7fcfa3a7b000 rw-p 00000000 00:00 0 
7fcfa3a7b000-7fcfa3aa1000 r-xp 00000000 08:01 786618                     /lib/x86_64-linux-gnu/ld-2.23.so
7fcfa3c6b000-7fcfa3c76000 rw-p 00000000 00:00 0 
7fcfa3c9d000-7fcfa3ca0000 rw-p 00000000 00:00 0 
7fcfa3ca0000-7fcfa3ca1000 r--p 00025000 08:01 786618                     /lib/x86_64-linux-gnu/ld-2.23.so
7fcfa3ca1000-7fcfa3ca2000 rw-p 00026000 08:01 786618                     /lib/x86_64-linux-gnu/ld-2.23.so
7fcfa3ca2000-7fcfa3ca3000 rw-p 00000000 00:00 0 
7ffcabfb2000-7ffcabfd3000 rw-p 00000000 00:00 0                          [stack]
7ffcabffa000-7ffcabffc000 r--p 00000000 00:00 0                          [vvar]
7ffcabffc000-7ffcabffe000 r-xp 00000000 00:00 0                          [vdso]
ffffffffff600000-ffffffffff601000 r-xp 00000000 00:00 0                  [vsyscall]

