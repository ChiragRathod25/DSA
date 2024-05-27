<!-- Determine current browser type -->
function Is() {
 var agent = navigator.userAgent.toLowerCase();
 this.major = parseInt(navigator.appVersion);
 this.minor = parseFloat(navigator.appVersion);
 this.ns = ((agent.indexOf('mozilla')!=-1) && ((agent.indexOf('spoofer')==-1) && (agent.indexOf('compatible') == -1)));
 this.ns2 = (this.ns && (this.major == 2));
 this.ns3 = (this.ns && (this.major == 3));
 this.ns4 = (this.ns && (this.major == 4));
 this.ns5 = (this.ns && (this.major > 4));
 this.ns6 = (this.ns && (agent.indexOf('netscape6')!=-1) );
 this.ns7 = (this.ns && (agent.indexOf('netscape/7')!=-1) );
 this.ns7pr = (this.ns && (agent.indexOf('netscape/7.0b1')!=-1) );
 this.ie = (agent.indexOf("msie") != -1);
 this.ie3 = (this.ie && (this.major == 2));
 this.ie4 = (this.ie && (this.major >= 4));
 this.op3 = (agent.indexOf("opera") != -1);
 this.pc  = (agent.indexOf("win") != -1);
}
