program aa;
const
    dx:array[1..4] of integer=(1,0,-1,0);
    dy:array[1..4] of integer=(0,1,0,-1);
var
    a:array[0..105,0..105] of integer;
    v:array[0..105,0..105] of boolean;
    i,j,n,l,r,mid,maxh,minh,h,ans:longint;
        flag:boolean;
           
procedure dfs(x,y,min,max:longint);
var
    i,j,x1,y1,h:longint;
begin
    if (a[x,y]<min)  or (a[x,y]>max) then exit;
    v[x,y]:=true;
    for i:=1 to 4 do
    begin
        x1:=x+dx[i];
        y1:=y+dy[i];
        if (x1>0)and(x1<=n)and(y1>0)and(y1<=n)and(v[x1,y1]=false) then
            if (a[x1,y1]<=max) and (a[x1,y1]>=min) then
                dfs(x1,y1,min,max);
    end;
end;                                                                    
function check(x,y:longint):boolean;
begin
    fillchar(v,sizeof(v),false);
    dfs(1,1,x,y);
    if v[n,n] then exit(true);
        exit(false);     
end;                                                                 
begin
    readln(n);
    maxh:=0;
    minh:=10000;
    for i:=1 to n do
    begin
        for j:=1 to n do
        begin
            read(a[i,j]);
            if a[i,j]<minh then minh:=a[i,j];
            if a[i,j]>maxh then maxh:=a[i,j];
        end;
        readln;
    end;
        l:=0;r:=maxh-minh;
    while l<=r do
    begin
        mid:=(l+r) shr 1;
        flag:=false;
        for h:=minh to maxh-mid do
            if check(h,h+mid) then
            begin
                flag:=true;
                break;
            end;
        if flag then begin ans:=mid;r:=mid-1;end
            else l:=mid+1;
    end;
    writeln(ans);
end.