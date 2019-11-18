import React from 'react';

import { Link } from 'react-router-dom';

export default function Header() {
  return (
    <div >
      <ul>
        <li>
          <Link to="/"></Link>
        </li>
        <li>
          <Link to="/feed">Feed</Link>
        </li>

      </ul>
    </div>
  );
}
