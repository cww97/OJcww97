program cx;   //½ò½òµÄ´¢Ðî¼Æ»®
var i,mum,money,use,temp:longint;

begin
  for i:=1 to 13 do
    begin
      if i=13 then break;
      inc(money,300);
      read(use);
      dec(money,use);
      if money>=100 then
        begin
          temp:=(money div 100)*100;
          inc(mum,temp);
          dec(money,temp);
        end;
      if money<0 then break;
    end;
  if i=13 then writeln(trunc(money+mum*1.2))
    else writeln(-i);
end.
