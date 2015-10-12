Remote debugging QWS VNC (crosscompiling).

(note that it is probably possible to find another, better, solution as I explained below. The goal
of this project was not to setup the best working tooling, it was to implement VNC authentication).

Compile and install complete QT library both on host and target. See compiling QT instructions.

Ofcourse install gdbserver on the CCGX.

Then compile the code. To work from the /src/gfxdrivers/vnc project, instead of from the /src/gui
project, make sure to have compiled Qt with the -plugin-gfx-vnc option, and not -qt-gfx-vnc.

Build the project. After compiling, every time copy the new (Crosscompiled) library into the host location:
sudo cp ~/dev/qt/plugins/gfxdrivers/libqgfxvnc.so /usr/local/qt4/plugins/gfxdrivers/

So that copies it over the same library, but then compiled for native use on the host.

Why is that necessary? Because otherwise GDB won't find the right libary, and you can't debug, set breakpoints etc.

Then start up debugging. To do that, compile the CCGX GUI against the same Qt version, and deploy that to the CCGX.
Not perse necessary, but I'd then stop that again, optionally close the gui project in Qt, and configure the
VNC plugin project to run /opt/color-control/gui/gui.

Start debugging, pause the file, and issue this command every time in the gdb command input:
set solib-search-path /home/matthijs/dev/qt/plugins/gfxdrivers

After that, you'll see in the breakpoint view that it found the file that belongs to the breakpoint. And
"info sharedlibrary" shows:

>~"0xb6fd87a0  0xb6ff2a78  Yes         /opt/venus/current/sysroots/armv7a-vfp-neon-ve-linux-gnueabi/lib/ld-linux.so.3\n"
>~"0xb6d52b68  0xb6f591f0  Yes         /usr/local/qt4/lib/libQtDeclarative.so.4\n"
>~"0xb6ae5fb0  0xb6c994f4  Yes         /usr/local/qt4/lib/libQtScript.so.4\n"
>~"0xb6a24f1c  0xb6aae814  Yes         /usr/local/qt4/lib/libQtSql.so.4\n"
>~"0xb66c6888  0xb6973be4  Yes         /usr/local/qt4/lib/libQtXmlPatterns.so.4\n"
>~"0xb6617784  0xb666b38c  Yes         /usr/local/qt4/lib/libQtDBus.so.4\n"
>~"0xb65d3424  0xb65f8944  Yes         /usr/local/qt4/lib/libQtXml.so.4\n"
>~"0xb5916f30  0xb638127c  Yes         /usr/local/qt4/lib/libQtGui.so.4\n"
>~"0xb56e50b4  0xb5790864  Yes         /usr/local/qt4/lib/libQtNetwork.so.4\n"
>~"0xb5401fc4  0xb5594110  Yes         /usr/local/qt4/lib/libQtCore.so.4\n"
>~"0xb53846e8  0xb53a66f4  Yes         /opt/venus/current/sysroots/armv7a-vfp-neon-ve-linux-gnueabi/usr/lib/libdbus-1.so.3\n"
>~"0xb5363fb0  0xb5371b94  Yes         /opt/venus/current/sysroots/armv7a-vfp-neon-ve-linux-gnueabi/lib/libpthread.so.0\n"
>~"0x4e2d0ba8  0x4e331150  Yes         /opt/venus/current/sysroots/armv7a-vfp-neon-ve-linux-gnueabi/usr/lib/libstdc++.so.6\n"
>~"0xb52f2bd0  0xb5321140  Yes         /opt/venus/current/sysroots/armv7a-vfp-neon-ve-linux-gnueabi/lib/libm.so.6\n"
>~"0x4e145180  0x4e1552a4  Yes         /opt/venus/current/sysroots/armv7a-vfp-neon-ve-linux-gnueabi/lib/libgcc_s.so.1\n"
>~"0xb51d18f0  0xb52c0dd8  Yes         /opt/venus/current/sysroots/armv7a-vfp-neon-ve-linux-gnueabi/lib/libc.so.6\n"
>~"0xb51ae760  0xb51b2224  Yes         /opt/venus/current/sysroots/armv7a-vfp-neon-ve-linux-gnueabi/lib/librt.so.1\n"
>~"0xb51a2968  0xb51a374c  Yes         /opt/venus/current/sysroots/armv7a-vfp-neon-ve-linux-gnueabi/lib/libdl.so.2\n"
>~"0xb41ca97c  0xb41cdb40  Yes         /usr/local/qt4/plugins/imageformats/libqgif.so\n"
>~"0xb3973c7c  0xb3976c04  Yes         /usr/local/qt4/plugins/imageformats/libqico.so\n"
>~"0xb392fb08  0xb39663d4  Yes         /usr/local/qt4/plugins/imageformats/libqjpeg.so\n"
>~"0xb3922890  0xb3924200  Yes         /usr/local/qt4/plugins/imageformats/libqtga.so\n"
>81^done
