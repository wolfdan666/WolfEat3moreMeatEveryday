rm -rf build
mkdir build
find . -name "*.out" | xargs rm -rf
git pull suanfa master
git add --all
git commit -m "`date '+%Y-%m-%d %H:%M:%S'`"
git push suanfa master
