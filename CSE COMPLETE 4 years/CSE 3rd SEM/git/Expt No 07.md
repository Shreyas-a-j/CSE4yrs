Expt No 07:



Write the command to create a light weight git tag named "V1.0" for a commit in your local repository.





Assume you have three commits in your local repository "myproj7" like this shown below.

1\.	**mkdir myproj7**

2\.	**cd myproj7**

3\.	**git init**

4\.	**notepad hello.c** (edit it, save it and close notepad)

5\.	**git add .**

6\.	**git commit -m "hello.c added"**

7\.	Do 4,5,and 6 for file "welcome.c" and "goodmorn.c" 

8\.	to see all commit history **git log --oneline** (or git log --all 

&nbsp;                                                    or git log --graph)

9\.	Example output shown below

&nbsp;       

&nbsp;	  **0a2ac5c** (HEAD -> master) goodmorn.c added

&nbsp;	  **a76610a** welcome.c added

&nbsp;	  **11c261a** hello.c added

&nbsp;         (The Bold letters shown above are the pointer for commits)

10\.	Now, suppose if you want to tag the **welcome.c added**  ie **a76610a** as version 	"V1.0" tag.do, **git tag V1.0 a76610a**     

&nbsp;	

&nbsp;	This above command creates a light weight tag named "V1.0" to the commit

&nbsp;	"a76610a"

11\.	Verify the tag by **git tag   (**see ouput)

12\.	To see for which commit it points to  **git show V1.0**

	

&nbsp;	output shown below:

&nbsp;	

commit a76610afcc549b593c9e451e7c277dd9096f029a (tag: V1.0)

Author: teamprojectabcd <teamprojectabcd@gmail.com>

Date:   Mon Nov 10 12:15:52 2025 +0530



&nbsp;   welcome.c added



diff --git a/welcome.c b/welcome.c

new file mode 100644

index 0000000..281583b

--- /dev/null

+++ b/welcome.c

@@ -0,0 +1 @@

+printf("Welcome to git lab\\n");

\\ No newline at end of file



