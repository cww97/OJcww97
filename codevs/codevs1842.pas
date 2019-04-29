program cx;
var x:longint;

function f(x:longint):longint;
begin
  if x>=0 then exit(5);
  exit(f(x+1)+f(x+2)+1);
end;

begin
  read(x);
  writeln(f(x));
end.
