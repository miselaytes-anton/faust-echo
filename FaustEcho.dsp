import("stdfaust.lib");
lp = fi.lowpass(1, 1000);
process = + : lp:lp:lp: _* 0.6 : ef.echo(2,1,0.5):re.satrev;