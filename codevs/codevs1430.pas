program cx;
var i,n:longint;
    ok:boolean;

begin
  read(n);
  ok:=true;
  for i:=2 to trunc(sqrt(n))+1 do
    if n mod i=0 then ok:=false;
  if ok then writeln('\t')
    else writeln('\n');
end.
