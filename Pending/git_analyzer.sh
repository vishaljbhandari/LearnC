#!/bin/bash
echo -e "=========================\n\n"
echo -e "Unchanged files names"
#git ls-files "*.h|*.hpp|*.c|*.cc|*.cpp|*.txt" --others
git ls-files --others

echo -e "\n\n=========================\n\n"
echo -e "Changed files names"
git diff --name-only > .tmp_git_file
cat .tmp_git_file
rm .tmp_git_file
echo -e "\n\n========================="
