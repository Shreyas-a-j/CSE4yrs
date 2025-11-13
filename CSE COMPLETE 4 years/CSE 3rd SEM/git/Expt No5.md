Expt No 5:

Fetch the latest changes from a remote repository and rebase your local branch on to the updated remote branch.



Rebasing means putting all your local branch commits on to top of the remote branch commits. we are updating commit tree by creating new base level.



Assume currently remote repository "team\_project" has one updated having file new.txt. we fetch this to our local machine by: **git fetch origin.**





You are working locally in the folder myproj5 under master branch. You have created two file hello.c and welcome.c and these files you have been committed in your master branch.



By doing:

**1.	git init**

**2.	notepad hello.c, edit it, save it and close notepad**

**3.	git add .**

**4.	git commit -m "hello.c added"**

**5.	notepad welcome.c, edit it, save it and close notepad**

**6.	git add .**

**7.	git commit -m "welcome.c added"**



Assume currently remote repository "team\_project" has one updated having file new.txt. Now fetch the updated remote branch to your local branch master



1. connect your local repo to GitHub:

          **git remote add origin "url link of remote git repository"**

2\.  \*\*git fetch origin  (\*\*This command shows remote branch has origin/main)

3\.  put all your local commits on top of origin/main:

           **git rebase origin/main**

4\.  Our local branch is master we forcefully change master to main by

           **git branch -M main**

5\.  Now push our local main to origin

           **git push -u origin main**

6\.  Finally check all commit log

&nbsp;          **git log --all**

