csft209
=======
如果要使用mmseg，请先下载安装coreseek版本的mmseg：
http://www.coreseek.cn/uploads/csft/3.2/mmseg-3.2.14.tar.gz
./configure && make && make install 

如果使用py数据源功能。请下载安装python-dev
http://www.python.org/ 2.6以上版本
或者使用apt-get 或者yum 等安装python-dev（或者python-devel）

使用csft，请clone代码后切换到r/csft5分支
git clone https://github.com/baisk/csft209.git
git checkout r/csft5

./configure --prefix=/opt/csft --enable-id64 --with-mmseg --with-python   (使用mmseg，使用pysource）
make && make install
