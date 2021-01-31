# CurrUserIsAdmin.h

```c
HRESULT CurrUserIsAdmin(void);
```

Return S_OK if current user is in Administrators user group, or S_FALSE otherwise.
If user A was Administrator but revoked itself from being one, this function will return false even though it didn't logged off and still possess the Administrator power.
