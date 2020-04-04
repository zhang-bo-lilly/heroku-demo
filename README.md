# README
This project demonstrates how to deploy a Node.js app that calls C/C++ function provided as a static library on the Heroku platform. Here are the steps for deploying this app. 

## Step 1. Start a Heroku application. 

```
> heroku create 
Creating app... done, ⬢ lit-tor-34919
https://lit-tor-34919.herokuapp.com/ | https://git.heroku.com/lit-tor-34919.git
```

You can also specify a unique app name that is all lowercase

```
> heroku create unique_all_lowercase_app_name 
```

## Step 2. Deploy the Heroku applicaiton 

```
> git push heroku master 
Enumerating objects: 9, done.
Counting objects: 100% (9/9), done.
Delta compression using up to 8 threads
Compressing objects: 100% (4/4), done.
Writing objects: 100% (6/6), 527 bytes | 131.00 KiB/s, done.
Total 6 (delta 3), reused 0 (delta 0)
remote: Compressing source files... done.
remote: Building source:
remote: 
remote: -----> Node.js app detected
remote:        
remote: -----> Creating runtime environment
remote:        
remote:        NPM_CONFIG_LOGLEVEL=error
remote:        NODE_ENV=production
remote:        NODE_MODULES_CACHE=true
remote:        NODE_VERBOSE=false
remote:        
remote: -----> Installing binaries
remote:        engines.node (package.json):  unspecified
remote:        engines.npm (package.json):   unspecified (use default)
remote:        
remote:        Resolving node version 12.x...
remote:        Downloading and installing node 12.16.1...
remote:        Using default npm version: 6.13.4
remote:        
remote: -----> Restoring cache
remote:        - node_modules
remote:        
remote: -----> Installing dependencies
remote:        Installing node modules (package.json)
remote:        
remote:        > nodejs-cpp@1.0.0 install /tmp/build_c62fc20a3bdbcf9194b8ffb56bb649f3
remote:        > node-gyp rebuild
remote:        
remote:        make: Entering directory '/tmp/build_c62fc20a3bdbcf9194b8ffb56bb649f3/build'
remote:          CC(target) Release/obj.target/nothing/node_modules/node-addon-api/src/nothing.o
remote:          AR(target) Release/obj.target/node_modules/node-addon-api/src/nothing.a
remote:          COPY Release/nothing.a
remote:          CXX(target) Release/obj.target/targetHello/src/main.o
remote:          CXX(target) Release/obj.target/targetHello/src/Wrappers.o
remote:          SOLINK_MODULE(target) Release/obj.target/targetHello.node
remote:          COPY Release/targetHello.node
remote:        make: Leaving directory '/tmp/build_c62fc20a3bdbcf9194b8ffb56bb649f3/build'
remote:        audited 284 packages in 6.413s
remote:        
remote:        1 package is looking for funding
remote:          run `npm fund` for details
remote:        
remote:        found 0 vulnerabilities
remote:        
remote:        
remote: -----> Build
remote:        Running build
remote:        
remote:        > nodejs-cpp@1.0.0 build /tmp/build_c62fc20a3bdbcf9194b8ffb56bb649f3
remote:        > node-gyp rebuild
remote:        
remote:        make: Entering directory '/tmp/build_c62fc20a3bdbcf9194b8ffb56bb649f3/build'
remote:          CC(target) Release/obj.target/nothing/node_modules/node-addon-api/src/nothing.o
remote:          AR(target) Release/obj.target/node_modules/node-addon-api/src/nothing.a
remote:          COPY Release/nothing.a
remote:          CXX(target) Release/obj.target/targetHello/src/main.o
remote:          CXX(target) Release/obj.target/targetHello/src/Wrappers.o
remote:          SOLINK_MODULE(target) Release/obj.target/targetHello.node
remote:          COPY Release/targetHello.node
remote:        make: Leaving directory '/tmp/build_c62fc20a3bdbcf9194b8ffb56bb649f3/build'
remote:        
remote: -----> Caching build
remote:        - node_modules
remote:        
remote: -----> Pruning devDependencies
remote:        removed 95 packages and audited 127 packages in 1.469s
remote:        found 0 vulnerabilities
remote:        
remote:        
remote: -----> Build succeeded!
remote: -----> Discovering process types
remote:        Procfile declares types -> web
remote: 
remote: -----> Compressing...
remote:        Done: 23M
remote: -----> Launching...
remote:        Released v4
remote:        https://lit-tor-34919.herokuapp.com/ deployed to Heroku
remote: 
remote: Verifying deploy... done.
To https://git.heroku.com/lit-tor-34919.git
   0ef51a0..31bb1b8  master -> master
```

## Step 3. Verify the result 

Open the URL for the app, and you should see 

```
{"0":5,"1":9,"2":7}
```

The app passed five integer values 5, 6, 7, 8, 9 to the C function which returns the min, max, and average. 
