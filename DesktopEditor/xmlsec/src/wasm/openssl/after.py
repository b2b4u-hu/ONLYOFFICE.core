import sys;
sys.path.append("../../../../../../build_tools/scripts");
import base;

base.replaceInFile("./deploy/openssl.js", "__ATPOSTRUN__=[];", "__ATPOSTRUN__=[function(){window.Asc.cryptoJS.onLoad();}];");
base.replaceInFile("./deploy/openssl.js", "__ATPOSTRUN__ = [];", "__ATPOSTRUN__=[function(){window.Asc.cryptoJS.onLoad();}];");
base.replaceInFile("./deploy/openssl.js", "function getBinaryPromise()", "function getBinaryPromise2()");

base.copy_file("./index.html", "./deploy/index.html");
base.copy_file("./code.js", "./deploy/code.js")