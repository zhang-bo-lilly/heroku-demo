const testNodeJSCPP = require('./build/Release/targetHello.node');
const express = require('express')
const PORT = process.env.PORT || 5000

const In = new Float64Array(5);
    In[0] = 5;
    In[1] = 6;
    In[2] = 7;
    In[3] = 8;
    In[4] = 9;
var Out = new Float64Array(3);

var app = express();

//app.get('/',function(req,res) {
//    res.send(testNodeJSCPP.runHello(7));
//});

app.get('/',function(req,res) {
    res.send(testNodeJSCPP.runCalc(In,Out));
});

app.listen(PORT, function() {
    console.log('Example app listening on port '+PORT);
});

console.log('Made it here')
