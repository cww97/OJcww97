program cx;
var i,kong,top:longint;
    st:string;
    a:array[0..1000]of string;

begin
  readln(st);
  st:=st+' ';
  repeat
    kong:=pos(' ',st);
    inc(top);
    a[top]:=copy(st,1,kong-1);
    delete(st,1,kong);
  until st='';
  for i:=top downto 2 do write(a[i],' ');
  writeln(a[1]);
end.
