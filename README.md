# qt

This is the 4.8.3 version of qt (http://code.qt.io/cgit/qt/qt.git/tag/?h=v4.8.3), with Victron Energy
additions, see commits.

Notes on the VNC Server:
  - We use it together with https://github.com/kanaka/noVNC: a javascript vnc client, and use
  https://github.com/kanaka/websockify as a proxy.
  - See branch for current status of implementing the VNC password.
  - Interesting for further development: I found this link: https://github.com/connectedtable/qt-libvncserver,
  which might be interesting: It uses the library LibVNCServer to act as a middle hand instead of the internal
  vnc plugin bundled with Qt. The one big issue with LibVNCServer is that it is GPL, so even when used as an
  dynamically loaded binary, it poses issues.
  - The QWS VNC Server was dropped in QT5. There is already someone who made it work again for Qt5:
  https://github.com/pigshell/qtbase. Note that that is meant for headless use. It has a memory framebuffer
  which has no relation to any local display - the whole idea was to run Qt apps headless. If the Multi:: option
  is still available in Qt5 hasn't been look into yet.
  
