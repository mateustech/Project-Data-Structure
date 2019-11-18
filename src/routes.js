import React from 'react'
import { Switch, Route, Redirect, BrowserRouter } from "react-router-dom";

import Feed from './pages/Feed'
import Login from './pages/Login'

function Routes() {
  return (
    <BrowserRouter>
      <Switch>
        <Route exact path="/" component={Login} />
        <Route path="/feed" component={Feed} />
      </Switch>
    </BrowserRouter>
  );
}

export default Routes;