import React from 'react';
import { Scale, Calculator, Clock, DollarSign, Building, Recycle, Users } from 'lucide-react';

const BenefitItem = ({ Icon, title, description }) => (
  <div className="flex flex-col items-center text-center mb-6">
    <div className="bg-white p-4 rounded-full shadow-lg mb-3">
      <Icon size={48} className="text-blue-500" />
    </div>
    <h3 className="font-bold text-lg mb-2">{title}</h3>
    <p className="text-sm">{description}</p>
  </div>
);

const BailReckoner = () => (
  <div className="bg-gradient-to-br from-blue-100 to-purple-100 p-8 rounded-lg max-w-4xl mx-auto">
    <h1 className="text-3xl font-bold text-center mb-8 text-blue-800">Bail Reckoner App</h1>
    
    <div className="grid grid-cols-3 gap-6">
      <BenefitItem 
        Icon={Scale}
        title="Fairness"
        description="Consistent bail amounts"
      />
      <BenefitItem 
        Icon={Calculator}
        title="Quick Calculation"
        description="Instant bail amount"
      />
      <BenefitItem 
        Icon={Clock}
        title="Time Efficient"
        description="Faster process"
      />
      <BenefitItem 
        Icon={DollarSign}
        title="Cost-Effective"
        description="Reduces manual work"
      />
      <BenefitItem 
        Icon={Building}
        title="System Savings"
        description="Lower admin costs"
      />
      <BenefitItem 
        Icon={Recycle}
        title="Eco-Friendly"
        description="Less paper use"
      />
    </div>
    
    <div className="mt-8 bg-white p-6 rounded-lg shadow-lg">
      <h2 className="text-2xl font-bold mb-4 text-purple-800 flex items-center">
        <Users className="mr-2" /> Overall Impact
      </h2>
      <p className="text-sm">
        Improves access to bail, supports financial planning, reduces unnecessary detention, 
        and promotes a more equitable and efficient judicial process.
      </p>
    </div>
    
    <div className="mt-8 flex justify-center">
      <img src="/api/placeholder/600/300" alt="Bail process illustration" className="rounded-lg shadow-lg" />
    </div>
  </div>
);

export default BailReckoner;
