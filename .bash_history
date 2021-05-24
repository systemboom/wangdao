vim setitimer_prof.c
./while1 
ps -elf|grep while1
ps -elf|grep while
cd ..
mkdir linuxDay17
cd linuxDay17
ll
cp ../linuxDay16/makefile makefile
ll
vim pthread_create.c
vim pthread_join.c
vim pthread_create_stack.c
vim pthread_exit.c
sudo vim /usr/include/func.h
cd wangdao/c/linuxDay17
ll
make
./pthread_j
./pthread_join 
make
./pthread_join_point 
make
./pthread_whil1 
maek
make
./pthread_cancel 
make
./pthread_cancel 
make
./pthread_cancel_malloc 
make
./pthread_cancel_malloc 
man 7 pthread_cleanup
man 7 pthread_cleanup_push
man  pthread_cleanup_push
make
./pthread_cleanup 
make
./pthread_cleanup 
make
./pthread_cleanup 
make
./pthread_cleanup 
make
./pthread_cleanup 
make
./pthread_cleanup 
cd wangdao/c/linuxDay17
ll
vim pthread_exit.c
vim pthread_join.c
vim pthread_join_point.c
vim pthread_whil1.c
ps -elLf
vim pthread_cancel.c
ps -elLf|grep cancel
vim pthread_cancel.c
vim pthread_cancel_malloc.c
vim pthread_cleanup.c
cd wangdao/c/linuxDay18
ll
vim pthread_cleanup.c
vim mutex_lockwice.c
vim mutex_locktwice.c
ps -elf|grep mutx
ps -elf|grep mutex
vim mutex_trylock.c
ll
vim mutex_locktwice.c
vim pthread_lock.c
vim pthread_other_unlock.c
vim pthread_add1000.c
vim pthread_recursive.c
vim pthread_errorcheck.c
cd wangdao/c/linuxDay18
cd wangdao/c/
mkdir linuxDay18
cd linuxDay18
cp ../linuxDay17/makefile makefile
ll
make
./pthread_cleanup 
make
rm mutex_lockwice
ll
mv mutex_lockwice.c mutex_locktwice.c
make
./mutex_locktwice 
make
ll
rm mutex_lockwice*
ll
make
./mutex_locktwice 
make
./mutex_locktwice 
make
./mutex_trylock 
make
./pthread_lock 
make
./pthread_other_unlock 
man gettimeofday
make
./pthread_add1000 
man gettimeofday
./pthread_add1000 
make
./pthread_recursive 
make
./pthread_recursive 
./pthread_errorcheck 
cd wangdao/c/linuxDay19
cd wangdao/c/
mkdir linuxDay19
cd linuxDay19
ll
cp ../linuxDay18/makefile makefile
maek
make
./pthread_cancel_lock 
make
./pthread_cancel_lock 
make
./pthread_cancel_lock 
make
./pthread_cancel_lock 
make
./pthread_cancel_lock 
make
./pthread_lock 
make
./sale_tickets 
make
kk
ll
cd cond/
ll
make
./pthread_cond 
make
./pthread_cond 
cd ../..
ll
cd 网盘
cd 网盘第五期/
ll
make
vim transferc.c 
cd ..
ll
cd linuxDay19
ll
make
cd cond/
ll
make
./pthread_broadcast 
make
./pthread_broadcast 
make
./pthread_broadcast 
make
./pthread_broadcast 
make
./pthread_broadcast 
make
./pthread_broadcast 
make
./pthread_broadcast 
make
./pthread_broadcast 
make
./pthread_broadcast 
make
./pthread_broadcast 
make
./pthread_broadcast 
make
./pthread_cond_signal 
make
./sale_tickets 
make
./sale_tickets 
make
./sale_tickets 
make
./sale_tickets 
cd wangdao/c/linuxDay19
vim pthread_cancel_lock.c
ps -elLf |grep pthread_cancel_lock
vim pthread_cancel_lock.c
vim pthread_lock.c
vim sale_tickets.c
ll
mkdir cond
mkdir mutex
ll
cp *.c mutex/
ll
cd mutex/
ll
cd ..
rm *.c
ll
mv pthread_* mutex/
mv sale_tickets mutex/
ll
cp makefile cond/
mv makefile mutex/
ll
cd cond/
ll
vim vim pthread_cond.c
ll
vim pthread_cond.c
vim pthread_broadcast.c
vim pthread_cond_signal.c
ll
vim sale_tickets.c
cd wangdao/c/linuxDay19
cd cond/
vim pthread_setdetach.c
cd wangdao/c/linuxDay19
ll
cd cond/
ll
make
./pthread_setdetach 
ipconfig
ipconfg
ifconfig
cd wangdao/c/linuxDay19
ll
cd cond/ 
vim pthread_timewait.c
vim pthread_wait.c
vim pthread_global.c
vim pthread_time_safe.c
byobu
vim sale_tickets.c
exit
byobu
vim pthread_time_safe.c
ll
mkdir wangdao/c/linuxDay21
mv sale_tickets.c wangdao/c/linuxDay21
cd wangdao/c/linuxDay21
ll
cp ../linuxDay19/mutex/makefile makefile
ll
make
vim sale_tickets.c 
ll
make
./sale_tickets 
byobu
cd wangdao/c/linuxDay21
ll
make
./sale_tickets2
cat /proc/sys/net/ipv4/tcp_fin_timeout 
cd wangdao/c/linuxDay21
ll
vim sale_tickets2.c
vim test.c
cd wangdao/c/
mkdir linuxDay22
cd linuxDay22
ll
cp ../linuxDay19/mutex/makefile makefile
ll
vim htons.c
vim inet_aton.c
vim gethostbyname.c
make
./gethostbyname www.baidu.com
vim gethostbyname.c
./gethostbyname www.sina.com
vim tcp_server.c
netstat -nat
vim tcp_client.c
make
./tcp_client 192.168.152.128 2000
cd ..
mkdir linuxday23
cd linux23
cd linuxday23/
cd ..
ll
rm linuxday23/
rm -r linuxday23/
mkdir linuxDay23
cd linuxDay23
cp ../linuxDay22/makefile makefile
ll
vim littleendian.c
vim tcp_server.c
cp ../linuxDay22/tcp_client.c tcp_client.c
ll
make
./tcp_client  192.168.152.128 2000
vim tcp_server.c
netstat -nat
man htons
sudo vim /usr/include/func.h 
netstat -nat
cd wangdao/c/linuxDay23
makie

./littleendian 
cat makefile
./sale_tickets 
cat makefile
make
ll
./tcp_server 
./tcp_server 192.168.37.128 2000
ifconfig
./tcp_server 192.168.152.128 2000
cd wangdao/c/linuxDay22
ll
make
./htons 
make
./htons 
gcc -g htons.c
ll
gdb a.out 
gdb ./a.out 
make
./htons 
make
./inet_aton 
./inet_aton 192.168.316
./inet_aton 192.168.3.16
man gethostbyname
man listen
man socket
man int socket
man bind
make
ifconfig
./tcp_server 192.168.152.128 2000
cd wangdao/c/
ll
mkdir linuxDay25
cd linuxDay25
cp ../linuxDay22/makefile makefile
ll
./tcp_client 192.168.152.128 2000
netstat -nat
./tcp_client 192.168.152.128 2000
cd wangdao/c/linuxDay25
ll
vim tcp_server.c
vim tcp_client.c
make
man epoll
make
man epoll
./tcp_server 
ifconfig 
./tcp_server 192.168.152.128 2000
ll
mkdir epoll_again
cd epoll_again/
ll
make
ll
rm *.o
ll
rm makefile 
cp ../makefile makefile
ll
make
ll
./tcp_server 192.168.152.128 2000
cd ..
mkdir epoll_et
cd epoll_et/
cd ..
cp makefile ./epoll_et/
ll
cd epoll_et/
ll
vim tcp_server.c
make
ll
make
vim tcp_server.c 
make
ll
./tcp_server 192.168.152.128 2000
rm tcp_server
ll
rm tcp_server*
 ./tcp_server 192.168.152.128 2000 ./tcp_server 192.168.152.128 2000
cp ../tcp_server.c
cp ../tcp_server.c tcp_server.c
ll
vim tcp_server.c 
ll
cd ..
ll
cp epoll_again/tcp_server.c epoll_et
ll
cd epoll_et
ll
vim tcp_server.c 
make
./tcp_server 
sudo vim /usr/include/func.h
cd wangdao/c/linuxDay25/epoll_et
ll
./tcp_client  192.168.152.128 2000
vim setNonblock.c
cd ..
ll
cd epoll_et
ll
man #include <fcntl.h>
man fcntl
cd wangdao/c/linuxDay25
ll
cd epoll_et/
vim tcp_server.c
ifconfig
./tcp_server 192.168.152.128 2000
netstat
netstat -nat
lsof -i :2000
kill -9 4644
kill -9 4645
netstat -nat
./tcp_server 192.168.152.128 2000
netstat -nat
cd ..
ll
make
mv ./epoll_et/setNonblock.c ./
ll
make
./setNonblock 
ll
cd epoll_et
ll
vim tcp_server.c
ll
mkae
make
man fcntl
make
vim setNonblock.c 
gcc setNonblock.c 
ll
make
cd ..
ll
sudo vim /usr/include/func.h 
cd wangdao/c/linuxDay
cd wangdao/c/linuxDay25
ll
cd epoll_et/
ll
ifconfig
ll
./client 192.168.152.128 2000
ll
chmod 777 client 
ll
chmod 777 server 
ll
./client 192.168.152.128 2000
netstat -nat
./client 192.168.152.128 2000
cd tcp_client/
ll
make
./client 192.168.152.128 2000
cd ../...
cd ../..
ll
cd ..
mkdir linuxDay26
ll
cd linuxDay26
ll
./tcp_client  192.168.152.128 2000
cd recv_peek/
ll
make
./tcp_client.c
chmod 777 tcp_client
chmod 777 tcp_client.c
chmod 777 tcp_server.c
make
ll
rm tcp_client.c tcp_server.c
ll
./tcp_client  192.168.152.128 2000
ll
cd ..
mkdir setsocket_rcvbuf
ll
cd setsocket_rcvbuf/
ll
./tcp_client  192.168.152.128 2000
cd ../
ll
cd recvlowat/
ll
cd tcp_client/
chmod 777 client 
ll
./client  192.168.152.128 2000
cd wangdao/c/linuxDay26
ll
mkdir io
cd io/
ll
chmod 777 server
ll
chmod 777 a.out 
ll
./a.out 
cd ../
cd aio/
ll
cp ../makefile makefile
ll
make
ll
chmod 777 a.out 
ll
cat test.txt 
ll
./a.out 
gcc aio_read.c -lrt
./a.out 
man writev
man iovec
man writev
sudo vim /usr/include/func.h 
man socketpair
man sendmsg
man cmsghdr
man cmsg
man recvmsg
git
cd ~
ll
git config --global systemboom
git config --global user.name systemboom
git config --global user.emailMRXWayneSteve@outlook.com
git config --global user.email MRXWayneSteve@outlook.com
git init
ssh-keygen -t rsa -C MRXWayneSteve@outlook.com
cd .ssh/
ls
cd id_rsa.pub
vim id_rsa.pub 
cat id_rsa.pub 
git remote add origin git@github.com:git@github.com:systemboom/wangdao.git
git remote 
git remote add origin git@github.com:systemboom/wangdao.git
cd wangdao/c/linuxDay26
cd io/
ll
cp ../makefile makefile
cd client/
ll
chmod 777 udp_client
ifconfig
./udp_client 192.168.152.128 9000
cd ..
mkdir aio
cd aio/
ll
./a.out 
cd ..
;;
ll
cd aio/
ll
gcc aio_read_sig.c -lrt
./a.out 
cd ..
ll
mkdir sendfd
cd sendfd
ll
cp ../makefile makefile
ll
vim writev.c
make
./writev 
ll
cat file1 
chmod 777 file1 
cat file1
ll
vim fork.c
make
./f
./fork 
mv file1 file
ll
./fork 
vim fork.c
make
./fork 
vim fork.c
make
./fork 
vim fork.c
make
./fork 
vim process_pool.h
cd wangdao/c/linuxDay27
ll
netstat -nat|grep 2000
cd tcp_client/
chmod 777 tcp_client
ll
chmod 777 client
ll
./client 192.168.152.128 2000 
netstat -nat|grep 2000
./client 192.168.152.128 2000 
netstat -nat|grep 2000
cd ~
ll
cd .git/
ll
cd ..
git remote
git remote -v
touch list
git init
git add list
git commit -m "list"
git push origin master
ssh -T git@github.com
find . -name ".git" | xargs rm -Rf
git init
ll
sudo apt-get update
sudo apt-get upgrade
git config --global user.name systemboom
MRXWayneSteve@outlook.com

git config --global user.email MRXWayneSteve@outlook.com
–
git config --global user.email MRXWayneSteve@outlook.com
git init
ssh-keygen -t rsa -C MRXWayneSteve@outlook.com
cd ~
cd .ssh/
ll
vim id_rsa.pub
cat id_rsa.pub 
cd ~
git commit -m "list"
touch file
cd .git
ll
cd ..
ll
cd wangdao
ll
git pull origin master
git pull origin wangdao
cd ~
git commit -m "file"
file
list
git push origin master
cd ./git
cd .git
git clone git@github.com:systemboom/wangdao.git
git remote -v
git push origin master
git branch -m master
git branch
git push -u origin +master​
ll
cd ../homework
cd ..
cd ./git 
cd .git
cd wangdao/
ll
cd .git/
ll
cd ..
git pull origin main 
ll
git add -all
git add --all
git commit -m "mj 2021-4-1"
git push origin main 
ll
cd ~
rm rm -rf .git
ll
rm file
rm list 
git config --global user.name systemboom
git config --global user.email MRXWayneSteve@outlook.com
git init
dx@dx-PC:~$ git init
ssh-keygen -t rsa -C MRXWayneSteve@outlook.com
cd ~/.ssh/
cat id_rsa.pub 
cd ~/wangdao/
mkdir git
cd git
ll
cd ..
mv git github
cd github/
ll
git clone git@github.com:systemboom/wangdao.git
cd ../c/linuxDay27
cd ..
git add linuxDay27
git commit -m "linuxDay27"
git push origin
git push --set-upstream origin master
git remote add origin git@github.com:systemboom/wangdao.git
git remote -v
git push origin master 
git add --all 
git bash here
cd ..
cd github/
ll
git pull origin master 
cd wangdao/
ll
cd ll
cp ../../c/linuxDay27 linuxday27
cp -r ../../c/linuxDay27 linuxday27
ll
cd linuxday27/
ll
cd ..
ll
cd wangdao/
ll
git pull origin main 
git add linuxday27/
git commit -m "linuxday27"
git push origin main 
cd ..
ll
cd github/
ll
tree 
cd ..
cd wangdao/c/
ll
cd ..
cd github/
kk
ll
cd wangdao/
ll
mv 进程池代码-详细注释版/ linuxday27/
ll
git pull origin main 
ll
git add --all 
git commit 
cd "/home/dx/wangdao/c/linuxDay28/trans_file/process_pool/"
ll
cd ..
cd tcp_client/
ll
rm process_pool 
rm makefile 
cp ../../../linuxDay22/makefile makefile
make
./tcp_client 192.168.152.128 2000
ll
rm oclient tcp_client.o
ll
rm tcp_client
ll

./tcp_client 192.168.152.128 2000
./tcp_client 192.168.152.128 2001
ll
make
./tcp_client 192.168.152.128 2001
./tcp_client 192.168.152.128 2002
ll
vim tcp_client.c
rm 'hello' 
ll
./tcp_client 192.168.152.128 2000
cat file 
ll
rm 'hello'$'\n'
ll
cd wangdao/c/linuxDay27
cd wangdao/c/linuxDay26
ll
cd ..
mkdir linuxDay27
ll
cd linuxDay27
ll
vim main.c
vun process_pool.h
vim process_pool.h
vim tcp_init.c
vim child.c
ll
vim send_fd.c
vim epoll.c
make
ifconfig
./process_pool 192.168.152.128 2000
./process_pool 192.168.152.128 200
./process_pool 192.168.152.128 2000 3 
cd ..
ll
cd ..
cd github/
cd wangdao/
ll
git add -all
git add --all
git commit -m "4-2"
git push origin main 
cd c
ll
cd ../..
cd c
ll
mkdir linuxDay28
ll
cd linuxDay28
ll
mkdir trans_file
ll
cd trans_file/
ll
vim trans_file.c
ll
vim trans_file.c
vim client.c
mv client.c tcp_client.c
vim tcp_client.c
ll
vim child.c
ll
echo hello>file
ll
mkae
make
mkdir tcp_client
ll
rm *.o
ll
mv tcp_client.c tcp_client
ll
mkdir process_pool
mv *.c process_pool
ll
cp makefile process_pool
cp makefile tcp_client/
ll
mv process_pool.h process_pool
ll
mv file process_pool/
ll
rm makefile 
cd process_pool/
make
cd ..
cd tcp_client/
ll
make
cd ../process_pool/
cat file 
./process_pool 
ifconfig
./process_pool 192.168.152.128 2000
./process_pool 192.168.152.128 2000 3
./process_pool 192.168.152.128 2000 
./process_pool 192.168.152.128 2000 3
./process_pool 192.168.152.128 2001 3
ll
rm *
ll
make
ll
chmod 0666 process_pool
ll
chmod 777 process_pool
./process_pool 192.168.152.128 2002 3
ll
netstat -nat
ll
vim child.c 
./process_pool 192.168.152.128 2000 3
vim trans_file.c 
rm process_pool
make
ll
./process_pool 192.168.152.128 2000 3
vim child.c 
cd.
cd ..
ll
cd trans_file/
tree
cd ..
cd wangdao/c/linuxDay28
ll
cd trans_file/
ll
cd tcp_client/
ll
rm file 
./tcp_client 192.168.152.128 2000
ll
md5sum file 
./tcp_client 192.168.152.128 2000
cd wangdao/c/linuxDay28
ll
cd trans_file/
ll
cd process_pool/
ll
rm file 
mv day16.zip file
ll
ifconfig
md5sum file
./process_pool 192.168.152.128 2000 3
ll
md5sum file
./process_pool 192.168.152.128 2000 3
cd ..
cd ~/wangdao/c/linuxDay28
ll
cd trans_file/
ll
cd process_pool/
ll
ifconfg
ifconfig
ll
./process_pool 
./process_pool 192.168.152.128 2000 3
md5sum file 
ll
./process_pool 192.168.152.128 2000 3
md5sum file ll
md5sum file 
cd wangdao/c/linuxDay28
ll
cd trans_file/
ll
cd tcp_client/
ll
vim tcp_client.c 
make
./client 192.168.152.128 2000
md5sum file 
cd ..
ll
mkdir tcp_client_size
cd tcp_client_size/
ll
cd ..
ll
cd trans_file/
ll
mkdir process_pool_size
cd process_pool
cd ..
cd process_pool_size/
cd ..
ll
cd process_pool_size/
ll
rm process_pool
ll
cat makefile 
vim trans_file.c 
make
cd ..
ll
cd tcp_client_size/
ll
vim tcp_client.c 
make
./client 192.168.152.128 2000
vim tcp_client.c 
make
./client 192.168.152.128 2001
vim tcp_client.c 
make
./client 192.168.152.128 2002
vim tcp_client.c 
make
./client 192.168.152.128 2002
./client 192.168.152.128 2000
cd ..
ll
mkdir tcp_client_time
cd tcp_client_time/
ll
rm client 
vim tcp_client.c 
ll
mkae
make
./client 192.168.152.128 2001
ll
md5sum file 
发的
df -h
cd ..
ll
cp c/linuxDay28 github/wangdao/
cp -r c/linuxDay28 github/wangdao/
git pull origin master 
cd github/wangdao/
ll
git add linuxDay28/
git commit -m "2020_4_28"
git push origin main 
cd wangdao/c/linuxDay28
ll
cd trans_file/process_pool/
ll
./process_pool 192.168.152.128 2000 3
md5sum file 
man fstat
cd ../process_pool_size/
ll
./process_pool 192.168.152.128 2000 3
cp ../process_pool/file 
cp ../process_pool/file file
ll
./process_pool 192.168.152.128 2000 3
./process_pool 192.168.152.128 2001 3
./process_pool 192.168.152.128 2002 3
./process_pool 192.168.152.128 2000 3
./process_pool 192.168.152.128 2001 3
cd wangdao/c/
mkdir linuxDay29
cd linuxDay29
pwd
/home/dx/wangdao/c/linuxDay29
ll
cd mmap/
ll
./process_pool 192.168.152.128 2000 3
md5sum file 
./process_pool 192.168.152.128 2000 3
vim trans_file.c 
mkae
make
./process_pool 192.168.152.128 2000 3
cd /home/dx/wangdao/c/linuxDay29
ll
mkdir mmap
cd mmap/
vim trans_file.c 
ll
make
ll
cd ..
ll
cd ..
cd linuxDay28
ll
pwd
cd trans_file/
ll
cd process_pool
ll
cp file ../../../linuxDay29/mmap/
cd ../../..
cd linuxDay29
ll
cd mmap/
ll
cd ..
cd tcp_client_size/
ll
make
ll
./client 192.168.152.128 2000 
cd ..
cd tcp_client_time/
ll
maek
make
./client 192.168.152.128 2000 
ll
md5sum file

maek
make
./client 192.168.152.128 2000 
vim tcp_client.c 
make
./client 192.168.152.128 2000 
md5sum file 
./client 192.168.152.128 2000 
cd wangdao/c/linuxDay29
ll
cd tcp_client_size/
ll
cd ..
ll
cd mmap/
ll
vim trans_file.c 
make
vim trans_file.c 
make
vim trans_file.c 
ll
make
cd ../tcp_client_size/
ll
rm file 
./client 192.168.152.128 2000 
cd .. 
ll
cd mmap2.0/
ll
cd mmap/
ll
cd src/
ll
rm process_pool
ll
vim trans_file.c 
make
ll
cd ../..
ll
cd tcp_client_size/
ll
rm client 
ll
vim tcp_client.c 
make
ll
./client 192.168.152.128 2000 
md5sum file 
cd wangdao/c/linuxDay29
cd mmap/
ll
md5sum file 
./client 192.168.152.128 2000 
./process_pool 192.168.152.128 2000 3
cd ..
cd linuxDay29
ll
cd mmap2
cd mmap2.0/
ll
cd mmap/
ll
cd src/
ll
./process_pool 192.168.152.128 2000 3
md5sum file 
man sendfile
cd "/home/dx/wangdao/c/linuxDay29/"
sudo vim /usr/include/func.h 
ll
cd sendfile/
ll
cd src/
ll
rm process_pool
vim trans_file.c 
make
ll
cp ../../../mmap2.0/mmap/src/file 
cp ../../../mmap2.0/mmap/src/file file
ll
./process_pool 192.168.152.128 2000 3
man splice
./process_pool 192.168.152.128 2000 3
tail
df
ds
man epoll
man epoll_weait
man epoll_wait
cd ../../...
cd ../../..
cd epoll_timeout/
ll
cd tcp_client/
ll
rm client 
make
ll
cd ..
cd tcp_server/
ll
rm server 
ll
make
ll
ifconfig
./server 192.168.152.128 2000
pwd
vim tcp_server.c 
make
ll
./server 192.168.152.128 2000
cd ..
ll
cd github/
ll
cd wangdao/
ll
git pull origin main 
git add ../../c/linuxDay29
cp -r ../../c/linuxDay29 linuxDay29
git add -all
git add --all
git diff
git diff master
git diff main
ll
git commit -m " "
git commit -m "20200506"
git push origin main 
cd ../..
cd c
ll
mkdir linuxDay30
kk
cd linuxDay30
kill -l
cd ..
cd linuxDay30
ll
cd process_pool_exit/
ll
cd process_pool_size/
ll
cd src/
ll
rm process_pool
ll
vim main.c 
make
ll
echo -n"hello">file
ll
cat file 
rm file 
ll
echo "hello" >file
ll
cat file 
./process_pool 192.168.152.128 2000 3
vim main.c 
cd ../..
cd ..
ll
cd process_pool_exit2.0/
ll
cd process_pool_size/
ll
cd src/
ll
rm process_pool
ll
vim send_fd.c 
vim child.c 
vim main.c
make
./process_pool 192.168.152.128 2000 3
md5sum fle
md5sum file 
ps -elf|grep process
kill -10 2105880
ps -elf|grep process
kill -10 2120602 
ps -elf|grep process
cd wangdao/c/linuxDay29
ll
mkdir sendfile
ll
cp -r mmap2.0/tcp_client_size/ sendfile/
cd sendfile/
ll
cd tcp_client_size/
ll
rm file 
ll
./client 192.168.152.128 2000 
md5sum file 
ll
vim tcp_client.c 
make
./client 192.168.152.128 2000 
md5sum file 
cd ..
ll
cd epoll_timeout/
ll
cd tcp_client/
ll;
ll
./client 192.168.152.128 
./client 192.168.152.128 2000
cd ..
ll
cd linuxDay30
ll
cd process_pool_exit/
ll
cd process_pool_size/
ll
cd src/
ll
cd "/home/dx/wangdao/c/linuxDay30/process_pool_exit/tcp_client_size/"
ll
rm client 
ll
make
./client 192.168.152.128 2000
cd ..
ll
cd process_pool_exit2.0/
ll
cd tcp_client_size/
ll
rm client 
ll
make
./client 192.168.152.128 2000
md5sum file 
cd ..
cd .
ll
cd ..
cd wangdao/
ll
cd github/
ll
cd wangdao/
cp ../../c/linuxDay30 linuxDay30
cp -r ../../c/linuxDay30 linuxDay30
ll
git pull origin main 
git add linuxDay30/
git commit
git commit 20200506
ll
git commit linuxDay30/
git commit -m "20200506"
git push origin main 
cd wangdao/c/
ll
mkdir linuxDay31
cd linuxDay31
cd threadpool1.0/
cd src/
make
ps -elLf|grep thread_pool
./thread_pool 
./thread_pool 1 1 3 10
cd "/home/dx/wangdao/c/linuxDay31/"
ps -elLf|grep threadpool
ps -elLf|grep thread_pool
tail -f
cd wangdao/c/linuxDay31
ll
cd 
ll
cd wangdao/c/linuxDay
cd wangdao/c/linuxDay31
ll
cd tcp_client_size/
ll
make
./client 192.168.152.128 2000
md5sum file 
cd wangdao/c/linuxDay31
ll
cd threadpool2.0
ll
cd src
ll
make
ll
ifconfig
./thread_pool 192.168.152.128 2000 3 10
ll
./thread_pool 192.168.152.128 2000 3 10
cd wangdao/c/linuxDay31
ll
cd threadpool2.0/
ll
cd src/
ll
vim main.c 
vim thread_pool.c
cd wangdao/c/linuxDay31
ll
cd wangdao/c/linuxDay31
ll
cd threadpool2.0/
ll
cd src/
ll
vim main.c 
cd ..
ll
cd ..
ll
mysql debian-sys-maint rlmJNG3PjH1xhOZ5
sudo mysql debian-sys-maint rlmJNG3PjH1xhOZ5
mysql -udebian-sys-maint -rlmJNG3PjH1xhOZ5
mysql -udebian-sys-maint -prlmJNG3PjH1xhOZ5
sudo service mysql restart
mysql -u root -p root
mysql -u root -p rootyes
mysql -u root -p root
sudo service mysql restart
mysql
mysql -u root -p
mysql -u localhost -p
mysql -u root -p root
mysql -u debian-sys-maint -p
mysql -u debian-sys-maint -p rlmJNG3PjH1xhOZ5
mysql -u debian-sys-maint -p
mysql
su root
sudo cat /etc/mysql/debian.cnf
lsb_release -a
ll
rm mysql-apt-config_0.8.12-1_all.deb 
ll
sudo dpkg -i mysql-apt-config_0.8.12-1_all.deb 
sudo apt-get update
sudo apt-get install mysql-server
mysql -u root -p
sudo mysql -u root -p
sudo service mysql start
sudo vim debian.cnf
sudo vim /etc/mysql/debian.cnf
sudo cat /etc/mysql/debian.cnf
dpkg --list|grep mysql
sudo apt-get remove mysql-common
dpkg --list|grep mysql
dpkg -l|grep ^rc|awk '{print$2}'|sudo xargs dpkg -P
dpkg --list|grep mysql
sudo apt-get autoremove --purge mysql-apt-config
dpkg --list|grep mysql
sudo apt-get update
sudo apt-get install mysql-server
systemctl status mysql
sudo mysql -u root -p
systemctl status mysql
sudo mysql -u root -p
mysql_upgrade -u root -p
sudo mysql -u root -p
sudo mysql -u dx -p
sudo cat /etc/mysql/debian.cnf
mysql sudo service mysql restart
service mysql restart
sudo mysql -u dx -p
/etc/init.d/mysql stop
mysql -u root
sudo /etc/init.d/mysql start
mysql -u root
# /usr/bin/mysqld_safe --skip-grant-tables
mysql -u root -pasdzxc
mysql -u root -p123456
mysql_upgrade -uroot -p123456
mysql -u root -p123456
mysql -P 3306 -h 127.0.0.1 -u root -p123456
ll
CREATE USER 'mysql.infoschema'@'localhost' IDENTIFIED BY '123456';
mysql -u root -p123456
sudo apt purge mysql-*
sudo apt autoclean
dpkg --list|grep mysql
sudo apt-get remove mysql-common
sudo apt-get autoremove --purge mysql-server-8.0
dpkg -l|grep ^rc|awk '{print$2}'|sudo xargs dpkg -P
dpkg --list|grep mysql
sudo apt-get autoremove --purge mysql-apt-config
sudo dpkg -i mysql-apt-config_0.8.10-1_all.deb
ll
sudo dpkg -i mysql-apt-config_0.8.10-1_all.deb
ll
sudo dpkg -i mysql-apt-config_0.8.12-1_all.deb 
ll
rm mysql-apt-config_0.8.12-1_all.deb 
ll
rm mysql-apt-config_0.8.12-1_all.deb 
ll
sudo dpkg -i mysql-apt-config_0.8.12-1_all.deb 
dpkg --list|grep mysql
sudo apt-get autoremove --purge mysql-apt-config 
sudo dpkg -i mysql-apt-config_0.8.10-1_all.deb
ll
sudo dpkg -i mysql-apt-config_0.8.12-1_all.deb 
dpkg --list|grep mysql
sudo apt-get autoremove --purge mysql-apt-config 
ll
sudo apt-get autoremove --purge
dpkg --list|grep mysql
sudo dpkg -i mysql-apt-config_0.8.17-1_all.deb 
sudo apt-get update
sudo apt-get install mysql-server
mysql -u root -pasdzxc
sudo apt-get install libmysqlclient-dev
cat /usr/include//mysql/
cat /usr/include/mysql/
cd  /usr/include/mysql/
ll
cat /usr/include/mysql
mysql -u root -q123456
cd ..
cd ~
mysql -u root -p123456
mysql -u root -q123456
mysql -u root -p
mysql -u root -p123456
mysql -u root -p
mysql -u root -pasdzxc
vi mysql/etc/my.cnf
vim /etc/mysql/my.cnf
sudo vim /etc/mysql/my.cnf
sudo service mysql restart
mysql -u root -p asdzxc -A --auto-rehash
mysql -u root -p -A --auto-rehash
cd wangdao/c/
ll
mkdir linuxDay32
cd linuxDay32
ll
mysqldump -u root -p 32th>32th.sql
ll
mysql -uroot -pasdzxc
ll
vim .mysql_history 
cd wangdao/
ll
cp -r c/linuxDay31 github/wangdao/
cp -r c/linuxDay32 github/wangdao/
git pull origin master 
git add --all
git commit -m "20200513"
git push origin master 
ll
cd wangdao/github/
cd wangdao/
df
mysql -u root -p123456
mysql -uroot -pasdzxc
ll
cd wangdao/
ll
cd c
ll
cd ..
cd githu 
cd github
cd wangdao/
ll
rm *
rm -r *
ll
cd .git/
ll
cd ..
mv -r c/* github/wangdao/
mv  c/* github/wangdao/
cd ..
cd wangdao/
ll
tree
cd c
cd ..
cd github/
cd wangdao/
git pull origin main 
ping www.baidu.com
git pull origin main 
git remote rm origin
git remote add origin git@github.com:systemboom/wangdao.git
git push -u origin master
git clone https://github.com/systemboom/wangdao.git
cd ..
git clone https://github.com/systemboom/wangdao.git
git push -u origin master
cd wangdao/
ll
git add --all
git commit -m'20200514'
git push origin main 
cd ~/.ssh
ll
cd ..
cd wangdao/github/
cd ~/.ssh
vim id_rsa.pub 
cat id_rsa.pub 
cd ~/wangdao/github/
cd wangdao/
git push -u origin master
git push -u origin main 
fd 
df -h
cd ..
rm c
rm c-r
rm -r c
ll
cd  wangdao/github/wangdao/
ll
cd linuxDay31
ll
cd ..
cd linuxDay32
ps -elf
ps -elf|grep mysql
mysql -uroot -pasdzxc
mysql -uroot -pasdzxc
service mysql start
mysql -uroot -pasdzxc
suo cat /etc/shadow
sudo cat /etc/shadow
cd wangdao/github/wangdao/
ll
cd linuxDay34
ll
mkdir crypt
cd crypt/
ll
vim main.c
vim makefile
make
ll
cat makefile 
./main dx
sudo ./main dx
vim main.c
sudo apt install linux-tools-common
sudo apt install linuex-tools-4.15***-generic
sudo apt install linux-tools-generic
cd ~
sudo perf stat ls
sudo apt install linux-tools-5.8.0-50-generic
perf
sudo perf stat ls
sudo perf stat -e raw_syscalls:sys_enter ls
sudo perf stat -e raw_syscalls:sys_enter ll
mysql -uroot -qasdzxc
mysql -uroot -pasdzxc
ll
cd wangdao/github/wangdao/
ll
mkdir linuxDay34
cd linuxDay34
ll
vim query.c 
make
vim makefile
ll
vim Makefile 
make
cd ..
cd linuxDay34
ll
chmod 777 query_mysql 
ll
./query_mysql 
./query_mysql hulk
ifconfig
vim query.c
make
vim query.c
make
vim query.c
make
vim query.c
make
vim query.c
make
ll
./query_mysql name
vim query.c
ifconfig
vim query.c
./query_mysql name
vim query.c
make
./query_mysql name
./query_mysql hulk
make
ll

vim query.c
make
./query_mysql hulk
vim query.c
make
ll;
./query_mysql hulk
vim query.c
make
./query_mysql hulk
vim update.c
make
vim update.c
make
vim update.c
make
vim update.c
ll
vim insert.c
make
vim query.c
make
ll
vim insert
vim insert.c
./insert_mysql 
vim insert.c
./insert_mysql 
vim insert.c
make
./insert_mysql 
find my.cnf
where is my.cnf
mysql --help|grep my.cnf
vim /etc/my.cnf
vim /etc/mysql/my.cnf
sudo vim /etc/mysql/my.cnf
service mysql restart
./insert_mysql 
sudo vim /etc/mysql/my.cnf
service mysql restart
service mysqld status
vim insert.c
make
./insert_mysql 
vim delete.c
make
./delete_mysql 
vim delete.c
make
./delete_mysql 
vim delete.c
make
./delete_mysql 
vim update.c
make
vim update.c
make
ll
rm update_mysql 
ll
make
ll
./update_mysql liu
vim update.c
make
./update_mysql liu
vim update.c
make
./update_mysql liu
perf
cd wangdao/github/wangdao/
ll
mkdir linuxDay35
cd linuxDay35
ll
vim test.c
gcc test.c
ll
sudo perf record -g ./a.out 
ll
sudo perf report -i perf.data \
sudo perf report -i perf.data 
vim test.c 
sudo perf record -g ./a.out 
sudo perf report -i perf.data 
sudo apt-get install valgrind
df
sudo apt-get update
sudo apt-get install valgrind
cd /var/lib/dpkg
sudo mv info info.baksudo
mkdir info
sudo mkdir info
sudo apt-get install valgrind
cd ~/wangdao/github/wangdao/
ll
rm valgrind.log.*
valgrind
vim malloc.c
gcc -g malloc.c 
valgrind --tool=memcheck --leak-check=full ./a.out 
cd wangdao/
ll
cd cpp
ll
cd ..
cd github/
cd wangdao/
mkdir c++day29
ll
cd c++day29/
ll
ls
clear
exit
netstat -n
netstat -na|grep tcp
netstat -ano -p tcp|grep 8888
cd wangdao/c/
cd wangdao/github/wangdao/
cd c++day30
ll
cd c
ll
./client 
ulimit -a
ulimit -n
cd wangdao/
cd ..
ifconfig
cd wangdao/
cd github/
ll
mkdir c++day30
cd c++day30
ll
sudo tcpdump -i ens33 -w test1.pcapng
ll
sudo tcpdump -i ens33 -S -w test1.pcapng
tcpdump: Couldn't change ownership of savefile
sudo tcpdump -i ens33 -S -w test1.pcapng
su root
ll
sudo tcpdump -i ens33 -S -w test2.pcapng
ll
ll -h
sudo tcpdump -i ens33 -S -w test3.pcapng
ll
vim test.c
gcc -o client client.c
ll
cd c
ll
gcc -o client client.c 
gcc -o server server.c 
ll
./server 
ping www.baidu.com
ifconfig
cd wangdao/
ll
cd github/
ll
cd wangdao/
ll
cd linuxDay30
ll
cd ..
ll
cd linuxDay35
ll
cd ..
cd c++day30
ll
mdkir c
mkjdir c
ll
mkdir 30
ll
mv 30 c
ll
cd c
ll
vim server,c
vim server.c
vim client.c
vim server.c
./client 
hello
ll
cd /
vim /etc/security/limits.conf 
man 2 shutdown
cd wangdao/github/wangdao/
ll
cd linuxDay31
ll
cd ..
cd c++day31
ll
cd ..
ll
cd c++day31
ll
mkdir test
cd test/
ll
cd networklib/
ll
cd v1
ll
cd networklib/
ll
cd ..
tree
cd ..
rm -r test/
ll
cd networklib/
ll
cd v1
ll
vim TestAcceptor.cc 
make
ll
./server.exe 
cd wangdao/github/wangdao/
ll
mkdir c++day31
cd c++day31
ll
vim TestAcceptor.cc
ll
cd c
ll
chmod 777 client
ll
./client 
ifconfig
./client 
cd "/home/dx/wangdao/github/wangdao/c++day31/networklib/v2/"
ll
vim TestEventLoop.cc 
ifconfig 
cd wangdao/github/
cd wangdao/
ll
cd linuxDay31
l
cd ..
cd c++day31
ll
cd ..
mkdir c++day32
cd c++day32
ll
cp r../c++day31/c
cp -r ../c++day31/c c
ll
cd v2
ll
make
ll
cd ..
cd v
cd v2/
ll
make
./server.exe 
vim TestEventLoop.cc 
make
vim TestEventLoop.cc 
./server.exe 
cd wangdao/github/wangdao/
ll
cd c++day32
ll
cd c/
ll
ifconfig
./client 
