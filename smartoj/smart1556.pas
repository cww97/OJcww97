program cx;
var i,ans,l,r:longint;
    st,st2:ansistring;

begin
  st:='';
  read(l,r);
  for i:=l to r do
    begin
      str(i,st2);
      st:=st+st2;
    end;
  ans:=0;
  for i:=1 to length(st) do
    if st[i]='2' then inc(ans);
  writeln(ans);
end.
