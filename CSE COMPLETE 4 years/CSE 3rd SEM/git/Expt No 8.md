Expt No 8:



Write the command to cherry-pick a range of commits from "source-branch" to the 

current branch. 





git cherry-pick <start-commit>^..<end-commit>



git cherry-pick command picks range of commits from start commit point to end commit point from one branch to another branch. <start-commit> is starting commit point and <end-commit> is ending commit point. 





Assume, your source branch is "master" and current branch is "feature"



First start working in master



1\. **mkdir myproj8**

2\. **cd myproj8**

3\. **git init**

4\. **notepad new.txt** (edit it, save it and close notepad)

5\. **git add .**

6\. **git commit -m "new.txt added"**

7\. check commit history log in "master": **git log --oneline**

   

&nbsp;  output shows as shown below:



&nbsp;  34d79df (HEAD -> master) new.txt added



Second create feature branch and start working there





1. **git branch feature**

2\. **git checkout feature**

3\. **notepad mytext1.txt** (edit it, save it and close notepad)

4\. **git add .**

5\. **git commit -m "mytext1.txt added"**

6\. do 3,4,and 5 for the files mytext2.txt,mytext3.txt,mytext4.txt and mytext5.txt

7\. check commit history log in "feature": **git log --oneline**    

&nbsp;  

&nbsp;  output shows as shown below:

&nbsp;  

&nbsp;  9adbe88 (HEAD -> feature) mytext5.txt added

&nbsp;  78e3fbe mytext4.txt added

&nbsp;  23dbc7a mytext3.txt added

&nbsp;  dbce617 mytext2.txt added

&nbsp;  6647dda mytext1.txt added

&nbsp;  34d79df (master) new.txt added



Third switch to your source branch "master" 

1. git checkout master
2. check commit history log in master: git log --oneline

&nbsp;  

&nbsp;  output shows as shown below:


   34d79df (HEAD -> master) new.txt added



3\. To cherry pick from 8eb204f to 961e586 from "feature" branch to 

&nbsp;   source branch "master":  **git cherry-pick dbce617^..78e3fbe**



4\. Now check commit history log in master: **git log --oneline**

&nbsp;  

&nbsp;  output shows as shown below

&nbsp;  

&nbsp;  7273594 (HEAD -> master) mytext4.txt added

&nbsp;  3e1717e mytext3.txt added

&nbsp;  8256ff7 mytext2.txt added

&nbsp;  34d79df new.txt added



&nbsp;  









