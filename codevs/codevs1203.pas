program cx;
var i,x,y:double;
    st:string;
begin
  //readln(st);
  ///kong:=pos(' ',st);
  //val(copy(st,1,kong-1),x);
 // val(copy(st,kong+1,length(st)-kong));
  read(x,y);
  if abs(x-y)<=0.00000001 then writeln('yes')
    else writeln('no');
end.
