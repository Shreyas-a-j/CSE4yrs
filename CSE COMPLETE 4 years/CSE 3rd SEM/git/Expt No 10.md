Expt No 10:



Write the command to list all commits made by the author "teamprojectabcd" between

"2023-01-01" and "2023-12-31."



we want to list all commits made by user "teamprojectabcd" (you can use your user name) since from date between 2025-11-12 and 2025-11-13



1\. **mkdir myproj10**

2\. **cd myproj10**

**3. git init**

4\. you commit two files hello.c and welcome.c

   on date 2025-11-12: **notepad hello.c** (edit it, save it and close notepad)

5\. **git add .**

6\. **git commit -m "hello.c added"**

7\. **notepad welcome.c** (edit it, save it and close notepad)

8\. **git add .**

9\. **git commit -m "welcome.c added"**

10\. you commit one file new.txt on 2025-11-13:

   **notepad new.txt** (edit it, save it and close notepad)

11.check all commits history: **git log --all**

 

   output shows as shown below:



  commit 7d3dc26ca88f056bfd2f14467819382126cf1fac (HEAD -> master)

  Author: teamprojectabcd [teamprojectabcd@gmail.com](mailto:teamprojectabcd@gmail.com)

  Date:   Thu Nov 13 09:31:10 2025 +0530



    new.txt added



  commit a7eab84650a7eec545059d39a03575368cbcd3e1

  Author: teamprojectabcd [teamprojectabcd@gmail.com](mailto:teamprojectabcd@gmail.com)

  Date:   Wed Nov 12 15:24:23 2025 +0530



    welcome.c added



  commit db8900c1374ffe2ea7dc0851c8e5fbf15989825a

  Author: teamprojectabcd [teamprojectabcd@gmail.com](mailto:teamprojectabcd@gmail.com)

  Date:   Wed Nov 12 15:23:24 2025 +0530



    hello.c added



12\. Now if you want to see commits made by author "teamprojectabcd"

    since from 2025-11-12 and until 2025-11-13:

    **git log --author="teamprojectabcd" --since="2025-11-12 --until="2025-11-13"**

 

    output shows as shown below:

 

    commit 7d3dc26ca88f056bfd2f14467819382126cf1fac (HEAD -> master)

    Author: teamprojectabcd [teamprojectabcd@gmail.com](mailto:teamprojectabcd@gmail.com)

    Date:   Thu Nov 13 09:31:10 2025 +0530



    new.txt added



    commit a7eab84650a7eec545059d39a03575368cbcd3e1

    Author: teamprojectabcd [teamprojectabcd@gmail.com](mailto:teamprojectabcd@gmail.com)

    Date:   Wed Nov 12 15:24:23 2025 +0530



    welcome.c added



    commit db8900c1374ffe2ea7dc0851c8e5fbf15989825a

    Author: teamprojectabcd [teamprojectabcd@gmail.com](mailto:teamprojectabcd@gmail.com)

    Date:   Wed Nov 12 15:23:24 2025 +0530



    hello.c added



 

