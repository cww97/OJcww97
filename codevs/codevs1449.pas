program cx;
var n:longint;

function fac(x:longint):longint;
begin
  if (x=0) or (x=1) then exit(1);
  exit(x*fac(x-1));
end;

begin
  read(n);
  writeln(fac(n));
end.
