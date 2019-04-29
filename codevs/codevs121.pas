program cx;
uses math;
var i,n,x,maxy,mini:longint;
begin
  read(n);
  mini:= maxlongint;
  maxy:=-maxlongint;
  for i:=1 to n do
    begin
      read(x);
      maxy:=max(maxy,x);
      mini:=min(mini,x);
    end;
  writeln(mini,' ',maxy);
end.;
