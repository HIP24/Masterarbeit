# Git 

## Git LFS

### Step 1: Install Git LFS

For Debian/Ubuntu systems, use the following commands:

```bash
curl -s https://packagecloud.io/install/repositories/github/git-lfs/script.deb.sh | sudo bash
sudo apt-get install git-lfs
```

### Step 2: Initialize Git LFS
After installation, set up Git LFS for your user account by running:
```bash
git lfs install
```

### Step optional: Untrack the file from Git:
Use the git rm --cached command to untrack the file1. For example, if your file is named largefile.zip, you would use:
```bash
git rm --cached largefile.zip
```

### Step 3: Track the Large File with Git LFS
Before adding and committing the file, you need to tell Git LFS to track it. You can do this with the git lfs track command. For example, if your large file is a .zip file, you would use:
```bash
git lfs track "*.zip"
```

Replace *.zip with the type of your large file. If you want to track a specific file, you can replace *.zip with the path to your file.

### Step 4: Add and Commit the File
After tracking the file with Git LFS, you can add it to your Git repository and commit it as usual:
```bash
git add your_large_file.zip
git commit -m "Add large file"
```

Replace your_large_file.zip with the path to your large file.

### Step 5: Push the File to Your Remote Repository
Finally, you can push your changes to your remote repository:
```bash
git push origin main
```
Replace main with the name of your branch if it’s not main.

By following these steps, Git LFS will handle your large files, and you should be able to push them to your remote repository without any issues.


Please replace `your_large_file.zip` and `main` with your actual file name and branch name respectively.





## Git Useful

### Untrack files to be ignored named “documentation/test” in git:
`git rm --cached <path>`  
<a href="https://kinsta.com/knowledgebase/gitignore-not-working/" target="_blank">How To Fix Gitignore Not Working</a>

### Remove a commit but keep the changes in your working directory
git reset --soft HEAD~1

