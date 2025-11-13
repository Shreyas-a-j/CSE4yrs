ExptNo 06:



Write the command to merge feature-branch into master while providing a custom commit message for the merge





1\.	create myproj6 folder under your own directory

&nbsp;              **mkdir myproj6**

2\.	change working directory to myproj6

&nbsp;              **cd myproj6**

3\.	Initialize git repository

&nbsp;              **git init** 

4\.	you working in master, create file hello.c

&nbsp;              **notepad hello.c** (edit it, save it and close notepad)

5\.	add hello.c file to staging area

&nbsp;              **git add .**

6\.	commit changes

&nbsp;              **git commit -m "hello.c added"**

7\.	create branch "feature-branch"

&nbsp;              **git branch feature-branch"**

8\.	switch to feature-branch

&nbsp;              **git checkout feature-branch**

9\.	you working in feature-branch, create file welcome.c

&nbsp;              **notepad welcome.c** (edit it, save it and close notepad)

10\.	add welcome.c to staging area

&nbsp;              **git add .**

11\.	commit changes

&nbsp;              **git commit -m "feature-branch updated"**

12\.	switch to master branch

&nbsp;              **git checkout master**

13	Merge the feature-branch into master with custom commit message

&nbsp;              **git merge --no-ff feature-branch -m "Merge feature-branch: added welcome.c"**

14\.	See all commit history log

&nbsp;             **git log --graph**



