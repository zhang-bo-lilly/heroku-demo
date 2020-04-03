## Step -2:
#Initialize a local git repo just for this example.
#Otherwise, Heroku can't recognize this project.
#Heroku looks for package.json in the root of the git repo

git init

## Step -1:
#Create the Procfile in this directory.

echo "web: node index.js" > Procfile

## Step 0: 
#Start a Heroku application.

heroku create my-heroku-app-lly-98765

## Step 0.1: 
#If necessary, explicitly set the buildpack. Heroku only supports 
#a limited list. 

heroku buildpacks:set heroku/nodejs

## Step 1: 
#Add the recently-created application git repo as remote

heroku git:remote -a 'my-heroku-app-lly-98765'

## Step 2:
#Do work. Edit the code, commit changes to the this repo

git commit --allow-empty -m "Test commit"

## Step 3: 
#Push the changes to the Heroku application. This triggers a (re)build of the C++ code. 

git push heroku master

#If this worked, Heroku should have successfully built the program and deployed it to the web.
#You can run:

heroku open

#to launch a browser pointed at the site.
# If something went wrong, you can see the Heroku log.

heroku logs -n 50
