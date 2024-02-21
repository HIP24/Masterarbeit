## File://0001.patch error 

cd meta-sigmatek/
git branch
code ../meta-sigmatek/
gitk
git rebase origin/master
git checkout master
git reset --hard
git checkout master
git pull
git fetch
git branch
git branch -D pamhal/virtualization
git branch
git pull
git fetch
git branch pamhal/virtual_master
git checkout pamhal/virtual_master
git branch
git status
git add recipes-kernel/stek-common/files/x86-64/defconfig
git commit
git push
git push --set-upstream origin pamhal/virtual_master
git branch
git pull
code .
../init.sh -b build -m sigmatek-core2 -d salamander
bitbake salamander-image -k
