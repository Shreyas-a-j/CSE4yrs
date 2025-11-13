Expt No 09:







Given a commit ID, how would you use Git to view the details of that specific 



commit, including the author, date, and commit message?











The commit ID you can view by git log --oneline, knowing specific commit ID you get details of that specific commit (author, when committed and commit message).







1\. **mkdir myproj9**



2\. **cd myproj9**



3\. **git init**

4\. **notepad hello.c** (edit it, save it and close notepad)



5\. **git add .**



6\. **git commit -m "hello.c added"**



7\. **notepad welcome.c** (edit it, save it and close notepad)



8\. **git add .**



9\. **git commit -m "welcome.c added"**



10\. **git log --oneline**







&nbsp;   output shows as shown below:







&nbsp;   a7eab84 (HEAD -> master) welcome.c added



&nbsp;   db8900c hello.c added







11\. To see the details of commit ID db8900c: **git show db8900c**



&nbsp;   



&nbsp;   The output shows as shown below:







&nbsp;   commit db8900c1374ffe2ea7dc0851c8e5fbf15989825a



&nbsp;   Author: navibaveen-b <navinaveen\\\_b@yahoo.co.in>



&nbsp;   Date:   Wed Nov 12 15:23:24 2025 +0530







&nbsp;   hello.c added







&nbsp;git a/hello.c b/hello.c



&nbsp;new file mode 100644



&nbsp;index 0000000..b8236ec



&nbsp; --- /dev/null



&nbsp; +++ b/hello.c



&nbsp; @@ -0,0 +1 @@



&nbsp;+printf("Hello World\\\\n");



\\\\ No newline at end of file







12\. if you want only metadata: **git show --no-patch db8900c**



&nbsp;   



&nbsp;   The output shows as ds



&nbsp; 



&nbsp; commit db8900c1374ffe2ea7dc0851c8e5fbf15989825a



&nbsp; Author: navinaveen-b <navinaveen\\\_b@yahoo.co.in>



&nbsp; Date:   Wed Nov 12 15:23:24 2025 +0530







&nbsp;  hello.c added













