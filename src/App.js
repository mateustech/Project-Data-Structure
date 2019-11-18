import React, { Fragment } from 'react';
import { BrowserRouter } from "react-router-dom";
import Routes from './routes';
import Header from './components/Header/Header';

export default function App() {
  return (

    <BrowserRouter>
      <Routes />
    </BrowserRouter>

  );
}
